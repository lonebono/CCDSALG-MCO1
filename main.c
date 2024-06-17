typedef char string[SIZE]; //just for strings in general

char top (string s)
{
    
    int lastSpaceIndex = -1;
    int i;
    string top;
    
    if(strlen(s) == 0)
    {
        return '\0';
    }
    else
    {
        for (i = 0; i < strlen(s); i++)
        {
                if (s[i] == ' ')
                {
                    lastSpaceIndex = i;
                }
        }
        
        return s[lastSpaceIndex + 1];
    }
}

void push(string s, string element)
{
    int x;

    if (strlen(s) == SIZE -1)
    {
        printf("\nOverflow Error!");
    }
    else
    {
        if (strlen(s) == 0)
        {
            s[strlen(s)] = *element;
        }
        else
        {
            s[strlen(s)] = ' ';
            strcat(s, element);
        }
    }
}

char pop(string s) 
{
    string popped;
    int i, lastSpaceIndex = -1;

    if (strlen(s) == 0) 
    {
        printf("\nUnderflow Error!");
        return top(s);
    } 
    else
    {
        for (i = 0; i < strlen(s); i++) 
        {
            if (s[i] == ' ') 
            {
                lastSpaceIndex = i;
            }
        }

        if (lastSpaceIndex != -1) 
        {
            strcpy(popped, &s[lastSpaceIndex + 1]);
            s[lastSpaceIndex] = '\0';
        } 
        else
        {
            strcpy(popped, s);
            s[0] = '\0';
        }

        return *popped;
    }
}


char queueHead (string s)
{
    
    if(strlen(s) == 0)
    {
        return '\0';
    }
    else
    {
        return s[0];
    }
}

char dequeue(string s) 
{
    string dequeued;
    int i, ctr = 0;

    if (queueHead(s) == '\0') 
    {
        printf("\nUnderflow Error!");
        return queueHead(s);
    } 
    else if (queueHead(s) == '&' || queueHead(s) == '|' || s[1] == '=')
    {
        strcpy(dequeued, s);
        if (queueHead(s) == '&') 
        {
            strcpy(dequeued, "&&");
        } 
        else if (queueHead(s) == '|')
        {
            strcpy(dequeued, "||");
        } 
        else if (s[1] == '=')
        {
            if (queueHead(s) == '>')
            {
                strcpy(dequeued, ">=");
            }
            if (queueHead(s) == '<')
            {
                strcpy(dequeued, "<=");
            }
            if (queueHead(s) == '=')
            {
                strcpy(dequeued, "==");
            }
            if (queueHead(s) == '!')
            {
                strcpy(dequeued, "!=");
            }
        }

        while (ctr != 3) 
        {
            for (i = 0; i < strlen(s); i++)
            {
                s[i] = s[i + 1];
            }
            ctr++;
        }

        s[strlen(s) - 1] = '\0';

        return *dequeued;
    } 
    else
    {
        strcpy(dequeued, s);

        while (ctr != 2) 
        {
            for (i = 0; i < strlen(s); i++)
            {
                s[i] = s[i + 1];
            }
            ctr++;
        }

        s[strlen(s) - 1] = '\0';

        return *dequeued;
    }
}
