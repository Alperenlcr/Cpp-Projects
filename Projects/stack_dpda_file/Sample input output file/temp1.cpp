#include <bits/stdc++.h>


using namespace std;
int main()
{
    string A;
    int c1 = 0;
    string str = "A:{,(,},)";
    string token1;
    istringstream s(str);
    while(getline(s, token1, ':'))
    {
        if(c1==1)
        {
            istringstream ss(token1);
            string token2;
            while(getline(ss, token2, ','))
                A.push_back(token2[0]);
        }
        c1 ++;
    }
    cout << A;

    return 0;
}

/*
            // 1. satiri aldin
            // : dan ayirdin
            char *end_str;
            char *token = strtok_r(line2, ":", &end_str);
            //ptr = strtok(line2, ":");
            c = 0;
            while(token!=NULL)
            {
                if (c == 1)
                {
                    // 1.yi " " dan ayirdin
                    char *end_token;
                    char *token2 = strtok_r(token, " ", &end_token);
        
                    //ptr2 = strtok(a, " ");
                    c1 = 0;
                    while (token2 != NULL)
                    {
                        if (c1 == 0)
                        {
                        // 0. yi , ile ayirip Q ya kopyaladin
                            char *end_token2;
                            char *token3 = strtok_r(token2, ",", &end_token2);
                            //ptr3 = strtok(c, ",");
                            c2 = 0;
                            while (token3 != NULL)
                            {
                                strcpy(Q[c2], token3);
                                c2 ++;
                                token3 = strtok_r(NULL, ",", &end_token2);
                                //ptr3 = strtok(NULL, ",");
                            }
                            //strcpy(ptr2, d);
                        }
                        else if (c1 == 2)
                        {
                        // 2. yi , ile ayirdin basini ve sonunu attin kalani start_end e kopyaladin
                            
                            char *end_token2;
                            char *token3 = strtok_r(token2, ",", &end_token2);
                            //ptr3 = strtok(c, ",");
                            c2 = 0;
                            while (token3 != NULL)
                            {
                                // convert char array to remove from beginning and end
                                string s(ptr3);
                                s.pop_back();
                                s.erase(s.begin());
                                // convert back for strcpy
                                char p[s.length()];
                                int k;
                                for (k = 0; k < sizeof(p); k++)
                                    p[k] = s[k];
                                strcpy(start_end[c2], p);
                                c2 ++;
                                token3 = strtok_r(NULL, ",", &end_token2);
                                //ptr3 = strtok(NULL, ",");
                            }
                            //strcpy(ptr2, d);
                        }
                        c1 ++;
                        token2 = strtok_r(NULL, " ", &end_token);
                        //ptr2 = strtok(NULL, " ");
                    }
                    //strcpy(ptr, b);
                }
                c ++;
                token = strtok_r(NULL, ":", &end_str);
                //ptr = strtok(NULL, ":");
            }*/