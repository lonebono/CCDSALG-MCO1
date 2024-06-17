typedef char string[SIZE]; //just for strings in general

void top(string s, string result) 
{
    int lastSpaceIndex = -1;
    int i;

    if (strlen(s) == 0) 
    {
        result[0] = '\0';
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
        if (lastSpaceIndex == -1) 
        {
            strcpy(result, s);
        } 
        else
        {
            strcpy(result, &s[lastSpaceIndex + 1]);
        }
    }
}

void push(string s, string element)
{
    if (strlen(s) == SIZE -1)
    {
        printf("\nOverflow Error!");
    }
    else
    {
        if (strlen(s) == 0)
        {
            strcpy(s, element);
        }
        else
        {
            s[strlen(s)] = ' ';
            strcat(s, element);
        }
    }
}

void pop(string s, string result)
{
    int i;
    int lastSpaceIndex = -1;
    string temp;

    if (strlen(s) == 0) 
    {
        printf("\nUnderflow Error!");
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
            top(s, temp);
            strcpy(result, temp);
            s[lastSpaceIndex] = '\0';
        } 
        else
        {
            top(s, temp);
            strcpy(result, temp);
            s[0] = '\0';
        }
    }
}

void queueHead(string s, string result)
{
    int firstSpaceIndex = -1;
    int i;

    if (strlen(s) == 0)
    {
        result[0] = '\0';
    }
    else
    {
        for (i = 0; i < strlen(s); i++)
        {
            if (s[i] == ' ')
            {
                firstSpaceIndex = i;
            }
        }
        if (firstSpaceIndex == -1)
        {
            strcpy(result, s);
        }
        else
        {
            while(s[i] != ' ')
            {
                result[i] = s[i];
            }
        }
    }
}


void enqueue(string s, string element)
{
    if (strlen(s) == 0)
    {
        strcpy(s, element);
    }
    else
    {
        s[strlen(s)] = ' ';
        strcat(s, element);
    }
}

void dequeue(string s, string result)
{
    string dequeued;
    int i, ctr = 0;
    int deleted;

    queueHead(s, dequeued);
    
    if (dequeued[0] == '\0')
    {
        printf("\nUnderflow Error!");
    }
    else
    {
        strcpy(result, dequeued);
        deleted = strlen(result);
        
        while (ctr != deleted)
        {
            for (i = 0; i < strlen(s); i++)
            {
                s[i] = s[i + 1];
            }
            ctr++;
        }
        s[strlen(s) - 1] = '\0';
    }
}
