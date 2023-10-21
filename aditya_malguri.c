#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


void insertDigit(Node** head, int digit) {
    printf("%d",digit);
    Node* newNode = createNode(digit);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}


Node* addLinkedLists(Node* num1, Node* num2) {
    int carry = 0;
    Node* result = NULL;
    Node* current = NULL;

    while (num1 || num2 || carry) {
        int sum = carry;
        if (num1) {
            sum += num1->data;
            num1 = num1->next;
        }
        if (num2) {
            sum += num2->data;
            num2 = num2->next;
        }

        carry = sum / 10;
        sum = sum % 10;

        insertDigit(&result, sum);
        if (current == NULL) {
            current = result;
        } else {
            current = current->next;
        }
    }

    return result;
}


Node* subtractLinkedLists(Node* num1, Node* num2) {
    int borrow = 0;
    Node* result = NULL;
    Node* current = NULL;

    while (num1 || num2) {
        int diff = borrow;
        if (num1) {
            diff += num1->data;
            num1 = num1->next;
        }
        if (num2) {
            diff -= num2->data;
            num2 = num2->next;
        }

        if (diff < 0) {
            diff += 10;
            borrow = -1;
        } else {
            borrow = 0;
        }

        insertDigit(&result, diff);
        if (current == NULL) {
            current = result;
        } else {
            current = current->next;
        }
    }

    return result;
}


Node* multiplyLinkedListByDigit(Node* num, int digit) {
    int carry = 0;
    Node* result = NULL;
    Node* current = NULL;

    while (num || carry) {
        int product = carry;
        if (num) {
            product += (num->data * digit);
            num = num->next;
        }

        carry = product / 10;
        product = product % 10;

        insertDigit(&result, product);
        if (current == NULL) {
            current = result;
        } else {
            current = current->next;
        }
    }

    return result;
}

void printLinkedList(Node* head) {
    while (head) {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}


void freeLinkedList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* num1 = NULL;
    Node* num2 = NULL;

    
    char input1[] = "12345678901234567890";
    char input2[] = "98765432100123456789";

    for (int i = 0; input1[i] != '\0'; i++) {
        insertDigit(&num1, input1[i] - '0');
    }
    printf("\n");
    for (int i = 0; input2[i] != '\0'; i++) {
        insertDigit(&num2, input2[i] - '0');
    }

    printf("\n");
    
    Node* sum = addLinkedLists(num1, num2);
    printf("Addition result: ");
    printLinkedList(sum);

   
    Node* difference = subtractLinkedLists(num1, num2);
    printf("Subtraction result: ");
    printLinkedList(difference);

    
    Node* product = multiplyLinkedListByDigit(num1, 3); 
    printf("Multiplication result: ");
    printLinkedList(product);

   
    freeLinkedList(num1);
    freeLinkedList(num2);
    freeLinkedList(sum);
    freeLinkedList(difference);
    freeLinkedList(product);

    return 0;
}
