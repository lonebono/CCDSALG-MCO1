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
        deleted = (int)strlen(result);
        
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
