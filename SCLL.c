
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int cf, px, py, pz;
    int flag;
    struct node *link;
};

typedef struct node NODE;

/* Create a new node */
NODE *getnode(void)
{
    NODE *x = (NODE *)malloc(sizeof(NODE));

    if (x == NULL)
    {
        printf("Insufficient memory\n");
        exit(EXIT_FAILURE);
    }

    x->cf = 0;
    x->px = 0;
    x->py = 0;
    x->pz = 0;
    x->flag = 0;
    x->link = NULL;

    return x;
}

/* Initialize circular linked list */
NODE *create_list(void)
{
    NODE *head = getnode();
    head->link = head;
    return head;
}

/* Insert a polynomial term at the rear */
NODE *insert_rear(int cf, int x, int y, int z, NODE *head)
{
    NODE *temp = getnode();
    NODE *cur = head;

    temp->cf = cf;
    temp->px = x;
    temp->py = y;
    temp->pz = z;
    temp->flag = 0;

    while (cur->link != head)
    {
        cur = cur->link;
    }

    cur->link = temp;
    temp->link = head;

    return head;
}

/* Read a polynomial */
NODE *read_poly(NODE *head)
{
    int cf, px, py, pz, ch;

    do
    {
        printf("\nEnter coefficient: ");
        scanf("%d", &cf);

        printf("Enter powers of x, y, z: ");
        scanf("%d%d%d", &px, &py, &pz);

        head = insert_rear(cf, px, py, pz, head);

        printf("Continue? Enter 1 for yes, 0 for no: ");
        scanf("%d", &ch);

    } while (ch == 1);

    return head;
}

/* Display a polynomial */
void display(NODE *head)
{
    NODE *temp = head->link;
    int first = 1;

    if (temp == head)
    {
        printf("Polynomial does not exist\n");
        return;
    }

    while (temp != head)
    {
        if (!first)
        {
            if (temp->cf >= 0)
                printf(" + ");
            else
                printf(" - ");
        }
        else if (temp->cf < 0)
        {
            printf("-");
        }

        printf("%d", abs(temp->cf));
        printf("x^%d y^%d z^%d",
               temp->px, temp->py, temp->pz);

        first = 0;
        temp = temp->link;
    }

    printf("\n");
}

/* Add two polynomials */
NODE *add_poly(NODE *h1, NODE *h2, NODE *h3)
{
    NODE *p1, *p2;
    int cf;

    /* Reset flags before addition */
    p2 = h2->link;

    while (p2 != h2)
    {
        p2->flag = 0;
        p2 = p2->link;
    }

    /* Match terms from the first polynomial */
    p1 = h1->link;

    while (p1 != h1)
    {
        p2 = h2->link;

        while (p2 != h2)
        {
            if (p1->px == p2->px &&
                p1->py == p2->py &&
                p1->pz == p2->pz)
            {
                break;
            }

            p2 = p2->link;
        }

        if (p2 != h2)
        {
            cf = p1->cf + p2->cf;
            p2->flag = 1;

            if (cf != 0)
            {
                h3 = insert_rear(cf, p1->px,
                                 p1->py, p1->pz, h3);
            }
        }
        else
        {
            h3 = insert_rear(p1->cf, p1->px,
                             p1->py, p1->pz, h3);
        }

        p1 = p1->link;
    }

    /* Add unmatched terms from the second polynomial */
    p2 = h2->link;

    while (p2 != h2)
    {
        if (p2->flag == 0 && p2->cf != 0)
        {
            h3 = insert_rear(p2->cf, p2->px,
                             p2->py, p2->pz, h3);
        }

        p2 = p2->link;
    }

    return h3;
}

/* Evaluate a polynomial */
void evaluate(NODE *head)
{
    NODE *temp = head->link;
    int x, y, z;
    double result = 0.0;

    printf("\nEnter values of x, y, z: ");
    scanf("%d%d%d", &x, &y, &z);

    while (temp != head)
    {
        result += temp->cf *
                  pow(x, temp->px) *
                  pow(y, temp->py) *
                  pow(z, temp->pz);

        temp = temp->link;
    }

    printf("Polynomial result is: %.2f\n", result);
}

/* Free all nodes, including the header */
void free_list(NODE *head)
{
    NODE *temp = head->link;
    NODE *next;

    while (temp != head)
    {
        next = temp->link;
        free(temp);
        temp = next;
    }

    free(head);
}

int main(void)
{
    NODE *h1, *h2, *h3, *eval;
    int ch;

    while (1)
    {
        printf("\n1. Evaluate polynomial\n");
        printf("2. Add two polynomials\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &ch) != 1)
            return 0;

        switch (ch)
        {
            case 1:
                eval = create_list();

                printf("\nEnter polynomial to evaluate:\n");
                eval = read_poly(eval);

                printf("\nPolynomial is: ");
                display(eval);

                evaluate(eval);
                free_list(eval);
                break;

            case 2:
                h1 = create_list();
                h2 = create_list();
                h3 = create_list();

                printf("\nEnter the first polynomial:\n");
                h1 = read_poly(h1);

                printf("\nEnter the second polynomial:\n");
                h2 = read_poly(h2);

                h3 = add_poly(h1, h2, h3);

                printf("\nFirst polynomial is: ");
                display(h1);

                printf("\nSecond polynomial is: ");
                display(h2);

                printf("\nSum of two polynomials is: ");
                display(h3);

                free_list(h1);
                free_list(h2);
                free_list(h3);
                break;

            case 3:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
