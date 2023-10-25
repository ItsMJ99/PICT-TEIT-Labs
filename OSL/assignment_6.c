#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

void fifo(int frames[], int n, char s[])
{
    int cf = 0;
    int pageFaults = 0;
    int pageHits = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        bool pageFound = false;

        // Check if the page is already in a frame
        for (int j = 0; j < n; j++)
        {
            if (frames[j] == s[i])
            {
                pageFound = true;
                pageHits++;
                break;
            }
        }

        if (!pageFound)
        {
            frames[cf] = s[i];
            pageFaults++;
        }

        // Display the frames and indicate hits/faults
        printf("Page %c:\t", s[i]);
        for (int j = 0; j < n; j++)
        {
            printf("%c\t", frames[j]);
        }
        if (pageFound)
        {
            printf("Hit\n");
        }
        else
        {
            printf("Fault\n");
        }

        cf = (cf + 1) % n; // Move to the next frame in a circular manner
    }

    printf("Page Faults : %d\n", pageFaults);
    printf("Page Hits : %d\n", pageHits);
}

void optimal(int frames[], int n, char s[])
{
    int pageFaults = 0;
    int pageHits = 0;
    int nextUse[n];

    for (int i = 0; i < n; i++)
    {
        nextUse[i] = -1;
    }

    for (int i = 0; i < strlen(s); i++)
    {
        bool pageFound = false;

        // Check if the page is already in a frame
        for (int j = 0; j < n; j++)
        {
            if (frames[j] == s[i])
            {
                pageFound = true;
                pageHits++;
                break;
            }
        }

        if (!pageFound)
        {
            // Page fault
            pageFaults++;

            if (pageFaults <= n)
            {
                // There are still empty frames, so simply add the page
                frames[pageFaults - 1] = s[i];
                nextUse[pageFaults - 1] = i;
            }
            else
            {
                // Find the page in frames that will not be used for the longest time
                int replaceIndex = 0;
                for (int j = 1; j < n; j++)
                {
                    if (nextUse[j] == -1)
                    {
                        replaceIndex = j;
                        break;
                    }
                    if (nextUse[j] > nextUse[replaceIndex])
                    {
                        replaceIndex = j;
                    }
                }
                frames[replaceIndex] = s[i];
                nextUse[replaceIndex] = -1;
                for (int j = i + 1; j < strlen(s); j++)
                {
                    if (s[j] == frames[replaceIndex])
                    {
                        nextUse[replaceIndex] = j;
                        break;
                    }
                }
            }
        }

        // Display the frames and indicate hits/faults
        printf("Page %c:\t", s[i]);
        for (int j = 0; j < n; j++)
        {
            printf("%c\t", frames[j]);
        }
        if (pageFound)
        {
            printf("Hit\n");
        }
        else
        {
            printf("Fault\n");
        }
    }

    printf("Optimal Page Faults: %d\n", pageFaults);
    printf("Optimal Page Hits: %d\n", pageHits);
}

bool checkHit(char page, char frames[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (frames[i] == page)
        {
            return true;
        }
    }
    return false;
}

void printFrame(char frames[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c\t", frames[i]);
    }
    for (int i = n; i < 3; i++)
    {
        printf("\t");
    }
}

void lru(int n, char s[])
{
    char frames[n];
    int occupied = 0;
    int pageFault = 0;
    int pageHits = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        printf("Page %c:\t", s[i]);

        if (checkHit(s[i], frames, n))
        {
            printFrame(frames, n);
            printf("Hit\n");
            pageHits++;
        }
        else if (occupied < n)
        {
            frames[occupied] = s[i];
            pageFault++;
            occupied++;
            printFrame(frames, n);
            printf("Fault\n");
        }
        else
        {
            int lruIndex = 0;
            int minUse = INT_MAX;

            for (int j = 0; j < n; j++)
            {
                int lastUse = INT_MAX;

                for (int k = i - 1; k >= 0; k--)
                {
                    if (s[k] == frames[j])
                    {
                        lastUse = k;
                        break;
                    }
                }

                if (lastUse < minUse)
                {
                    minUse = lastUse;
                    lruIndex = j;
                }
            }

            frames[lruIndex] = s[i];
            pageFault++;
            printFrame(frames, n);
            printf("Fault\n");
        }
    }

    printf("LRU Page Faults: %d\n", pageFault);
    printf("LRU Page Hits: %d\n", pageHits);
}

int main()
{
    char s[100];
    printf("Enter String: ");
    scanf("%s", s);

    int n;
    printf("Enter the number of frames: ");
    scanf("%d", &n);

    int frames[n];
    printf("\nFIFO Solution : \n");
    fifo(frames, n, s);

    int oframes[n];
    printf("\nOprimal Solution : \n");
    optimal(oframes, n, s);

    int lruframes[n];
    printf("\nLRU Solution : \n");
    lru(n, s);

    return 0;
}