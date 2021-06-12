// Recursive attempt at checking the pset3's tideman locked 2d array
// Checks the existence of loops

#include <stdio.h>
#include <cs50.h>

bool loop(int depth, int cand);
bool looper(void);

// No loop locked
bool zlocked[4][4] = {
    {false, true, false, false},
    {false, false, true, true}, 
    {false, false, false, false}, 
    {false, false, true, false}};

int candidate_count = 4;

// Locked loop
bool locked[4][4] = {
    {false, true, false, false},
    {false, false, true, true}, 
    {false, false, false, false}, 
    {true, false, true, false}};

int main(void)
{
    bool result = looper();
//    bool result = loop(0, 0);
    char *resultb = NULL;

//    char *s = "joder";
    if (result)
    {
        resultb = "true";
    }
    else
    {
        resultb = "false";
    }

    printf("Output of recursive function: %s\n", resultb);

}

bool looper(void)
{   
    for (int cand = 0; cand < candidate_count; cand++)
    {
        if (loop(0, cand))
        {
            return true;
        }
        printf("--------------------\n");
    }
    return false;
}

bool loop(int depth, int cand)
{
    printf("Entering loop, depth: %i, cand:%i\n", depth, cand);
    if (depth > candidate_count)
    {
        printf("Returning loop, depth: %i, cand:%i, return: 'true', maxdepth reached\n", depth, cand);
        return true;
    }    
    
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[cand][i])
        {
            if (loop(depth + 1, i))
            {
                return true;
            }
        }
    }
    printf("Returning loop, depth: %i, cand:%i, return: 'false', nowhere to go\n", depth, cand);
    return false;
}


// Todooooooooooooooooo, rethink again, watch recursion video.
//bool loop(int origin)
//{
//    printf("Calling loop with origin: %i\n",  );
//    // Recursively check existence of loop, cand is candidate where to go 
//    if (cand == origin)
//    {
//        return true;
//    }
//    
//    for (int i = 0; i < candidate_count; i++)
//    {
//        if (locked[cand][i])
//        {
//            return loop(cand, i);
//        }
//    }
//    return false;
//
//}
//
