/*
DSA Assignment 
ALI HAMZA MALIK
BEE11-B
*/

#include <iostream>
using namespace std;


string openbrackets = "{[(";
string closedbrackets = "}])";
string digits = "0123456789";
string operators = "/*+-";

int MAX_Stack_size = 100;

struct Node
{
    int data;
    Node *next;
};

struct stack
{
    struct Node *head;
    struct Node *top;
};

Node *Create_Node(int data)
{
    Node *x = new Node;
    x->data = data;
    x->next = NULL;
    return x;
}

stack *init_stack()
{
    stack *s = new stack;
    s->head = NULL;
    s->top = NULL;
    return s;
}

int IsEmpty(stack *s)
{
    if (s->top == NULL)
    {
        return 1;
    }
    return 0;
}

//push
void push(stack *s, int val)
{

    if (IsEmpty(s))
    { //empty
        Node *n;
        n = Create_Node(val);
        s->head = n;
        s->top = n;
    }
    else if (abs((s->top - s->head) / 2) == MAX_Stack_size)
    {
        printf("------------------------ Stack Overflow ------------------------\n");
    }
    else
    {
        Node *n;
        n = Create_Node(val);
        s->top->next = n;
        s->top = n;
    }
}

//pop
int pop(stack *s)
{
    if (IsEmpty(s))
    {
        printf("------------------------ Stack Underflow ------------------------\n");
        return -1;
    }
    else
    {
        int tmp = s->top->data;
        if (s->top == s->head)
        {
            delete s->top;
            s->top = NULL;
            s->head = NULL;
        }
        else
        {
            Node *temp = s->head;
            while (temp->next != s->top)
                temp = temp->next;
            temp->next = NULL;
            delete s->top;
            s->top = temp;
        }
        return tmp;
    }
}

void ReverseStack(stack *s)
{
    stack *r = init_stack();
    while (s->head != NULL)
    {
        int tmpval = pop(s);
        push(r, tmpval);
    }
    *s = *r;
}

void print_stack_val(stack *s)
{
    if (IsEmpty(s))
    {
        printf("Stack is Empty");
    }
    else
    {
        Node *tmp = s->head;
        while (tmp != NULL)
        {
            printf("%d ", tmp->data);
            tmp = tmp->next;
        }
    }
    printf("\n");
}

void print_stack_char(stack *s)
{
    if (IsEmpty(s))
    {
        printf("Stack is Empty");
    }
    else
    {
        Node *tmp = s->head;
        while (tmp != NULL)
        {
            printf("%c ", tmp->data);
            tmp = tmp->next;
        }
    }
    printf("\n");
}

void print_charint(stack *s2)
{

    if (IsEmpty(s2))
    {
        printf("Stack is Empty");
    }
    else
    {
        Node *tmp = s2->head;
        while (tmp != NULL)
        {
            if (tmp->data < 127)
            {
                printf("%c ", tmp->data);
            }
            else
            {
                printf("%d ", tmp->data - 127);
            }
            tmp = tmp->next;
        }
    }
    printf("\n");
}

int checkin(string a, char b)
{
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == b)
        {
            return i + 1;
        }
    }
    return 0;
}

bool CheckValidity(string text)
{
    for (int i = 0; i < text.length(); i++)
    {
        if (!checkin(digits + operators + openbrackets + closedbrackets, text[i]))
        {
            return 0;
        }
    }

    stack *s = init_stack();
    for (int i = 0; i < text.length(); i++)
    {
        if (checkin(openbrackets, text[i]))
        {
            //cout<<"--"<<text[i]<<"--";
            push(s, text[i]);
        }

        if (checkin(closedbrackets, text[i]))
        {
            char ch = pop(s);
            int xi;
            //cout<<"===>"<<ch<<"==== ";
            for (xi = 0; xi < sizeof(closedbrackets); xi++)
            {
                if (openbrackets[xi] == ch)
                {
                    break;
                }
            }
            //cout<<closedbrackets[xi]<<" ---> "<<char(text[i])<<endl;

            if (text[i] != closedbrackets[xi])
            {
                return 0;
            }
        }
    }
    if (!IsEmpty(s))
    {
        return 0;
    }

    return 1;
}

int CheckOperatorPrecidence(stack *t, int precedence)
{
    int ch1, ch2;
    ch1 = checkin(operators, precedence) > 2;
    Node *tmp = t->head;
    while (tmp != NULL)
    {
        if (checkin(operators, tmp->data))
        {
            ch2 = checkin(operators, tmp->data) > 2;
            if (ch1 && !ch2)
            {
                cout << char(tmp->data) << " " << ch1 << " " << ch2 << endl;
                return 1;
            }
        }
        tmp = tmp->next;
    }
    return 0;
}

int CheckBracketPrecidence(stack *t, int precedence)
{
    int ch1, ch2;
    ch1 = checkin(closedbrackets, precedence);
    Node *tmp = t->head;
    while (tmp != NULL)
    {
        ch2 = checkin(openbrackets, tmp->data);
        if (ch2)
        {
            if (ch1 == ch2)
            {
                return 1;
            }
        }
        tmp = tmp->next;
    }
    return 0;
}

void stack_to_post(stack *t, stack *s, int precedence)
{
    int tmp;
    int xi = checkin(closedbrackets, precedence) - 1;
    while (1)
    {
        tmp = pop(t);
        if (tmp == openbrackets[xi])
        {
            break;
        }
        else if (checkin(operators, tmp))
        {
            push(s, tmp);
        }
    }
}

void Infix_to_Postfix(stack *s2, string text)
{
    stack *s1 = init_stack();
    string tmpstr;
    for (int i = 0; i < text.length(); i++)
    {
        if (checkin(digits, text[i]))
        {
            tmpstr = text[i];
            for (int j = i + 1; j < text.length(); j++)
            {
                if (!checkin(digits, text[j]))
                {
                    i = j - 1;
                    break;
                }
                else
                {
                    tmpstr += text[j];
                }
            }
            int tpval;
            sscanf(tmpstr.c_str(), "%d", &tpval);
            push(s2, tpval + 127);
        }
        else if (checkin(openbrackets, text[i]))
        {
            push(s1, text[i]);
        }
        else if (checkin(closedbrackets, text[i]))
        {
            stack_to_post(s1, s2, text[i]);
        }
        else if (checkin(operators, text[i]))
        {
            push(s1, text[i]);
        }
    }
    while (s1->top != NULL)
    {
        push(s2, pop(s1));
    }
    ReverseStack(s2);
}

int EvaluatePostfix(stack *s)
{
    stack *s1 = init_stack();
    int tmpval;
    while (s->head != NULL)
    {

        tmpval = pop(s);
        if (tmpval > 127)
        {
            push(s1, tmpval - 127);
        }
        else
        {
            int val1 = pop(s1);
            int val2 = pop(s1);
            switch (tmpval)
            {
            case '/':
                push(s1, (val2 / val1));
                break;
            case '*':
                push(s1, (val2 * val1));
                break;
            case '+':
                push(s1, (val2 + val1));
                break;
            case '-':
                push(s1, (val2 - val1));
                break;
            }
            
        }
    }
    return ((s1->top->data));
}


int main()
{
    system("CLS");
    system("clear");
    string text;

    while (1)
    {
        cout << "Enter Equation or E for exit: ";
        cin >> text;
        if(text=="e" || text=="E"){break;}
        int validityCheck;
        validityCheck = CheckValidity(text);
        
        if (!validityCheck)
        {
            cout << "ERROR INVALID STATEMENT" <<endl<<"TRY AGAIN"<<endl;
            continue;
        }
        else
        {
            stack *s = init_stack();
            Infix_to_Postfix(s, text);
            cout << "RESULT="<<EvaluatePostfix(s)<<endl;
        }
    }

    cout<<"EXITING PROGRAM";

    //{[(12+3)-2]*((2*3)+9)/2}
    //{[(12+3)]}

        //text="122+((2*2)-1)/1";
    //"[(1-3)-2]+(2*6)";
    //"[(12+3)-2]+(23*6)";
    //[(12+3)-2]*((2*3)+9)/1
    //"122+((2*2)-1)/2"

    //"{[(12+3)-2]*((2*3)+9)/2}";
    //"{(2+8)*((3-5)/2)}"
    

    return 0;
}
