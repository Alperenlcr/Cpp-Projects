

/*


void display(vector<string> all_list, ofstream &fw)
{
    int i, j;
    vector<vector<string>> letter_to_shorter;
    letter_to_shorter.push_back(vector<string> ());
    letter_to_shorter.back().push_back(all_list[0]);
    for ( i = 1; i < all_list.size(); i++)
    {
        if (letter_to_shorter.back().back()[0] == all_list[i][0])
        {
            letter_to_shorter.back().push_back(all_list[i]);
        }
        else
        {
            letter_to_shorter.push_back(vector<string> ());
            letter_to_shorter.back().push_back(all_list[i]);
        }
        //cout << all_list[i] << endl;
    }
    for ( i = 0; i < letter_to_shorter.size(); i++)
    {
        string temp = commonPrefix(letter_to_shorter[i]);
        if (count(letter_to_shorter[i].begin(), letter_to_shorter[i].end(), temp) != 1)
            letter_to_shorter[i].insert(letter_to_shorter[i].begin(), temp);
    }
    
    for ( i = 0; i < letter_to_shorter.size(); i++)
    {
        for ( j = 0; j < letter_to_shorter[i].size(); j++)
        {
            cout << letter_to_shorter[i][j] << " ";
            //letter_to_shorter.erase(letter_to_shorter.begin());
        }
        cout << "\n";
    }
}

// function to display the content of Trie
void prep_display(struct TrieNode* root, char str[], int level, vector<string> &all_list)
{
    // If node is leaf node, it indicates end
    // of string, so a null character is added
    // and string is displayed
    if (root->isEndOfWord != false) 
    {
        str[level] = '\0';
        string temp(str);
        temp.append("(");
        temp.append(root->English);
        temp.append(")");
        all_list.push_back(temp);
    }

    int i;
    for (i = 0; i < ALPHABET_SIZE; i++) 
    {
        // if NON NULL child is found
        // add parent key to str and
        // call the display function recursively
        // for child node
        if (root->Dothraki[i]) 
        {
            str[level] = i + 'a';
            prep_display(root->Dothraki[i], str, level + 1, all_list);
        }
    }
}

void tab(struct TrieNode* root, string key)
{
    struct TrieNode *iter = root;
    int count, i ,j, index;
    
    for ( i = 0; i < key.length()-1; i++)
    {
        count = 0;
        index = key[i] - 'a';
        for ( j = 0; j < ALPHABET_SIZE; j++)
            if(iter->Dothraki[index]->Dothraki[j])
                count ++;

        if (count > 1)
            for ( j = 0; j < count; j++)
                cout << "\t";
        
        iter = iter->Dothraki[index];
    }
    cout << "-";
}

// function to display the content of Trie
void display(struct TrieNode* root, struct TrieNode* head, char str[], int level)
{
    // If node is leaf node, it indicates end
    // of string, so a null character is added
    // and string is displayed
    if (root->isEndOfWord != false) 
    {
        str[level] = '\0';
        string key(str);
        tab(head, key);
        cout << str << "(" << root->English << ")" << endl;;
    }
  
    int i;
    for (i = 0; i < ALPHABET_SIZE; i++) 
    {
        // if NON NULL child is found
        // add parent key to str and
        // call the display function recursively
        // for child node
        if (root->Dothraki[i]) 
        {
            str[level] = i + 'a';
            display(root->Dothraki[i], head, str, level + 1);
        }
    }
}
void liste(struct TrieNode* root)
{
    int i, j, count;
    if (root->isEndOfWord)
    {
        cout << "(" << root->English << ")" << endl;
    }
    
    for (i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->Dothraki[i])
        {
            cout << (char)(i + 'a');
            liste(root->Dothraki[i]);
        }
    }
}


// A Function that returns the longest common prefix
// from the array of strings
string commonPrefix (vector<string> arr)
{
    string prefix =  arr[0];
    int i;
    for ( i=1; i < arr.size(); i++)
        prefix = commonPrefixUtil(prefix, arr[i]);
 
    return (prefix);
}

string commonPrefixUtil(string str1, string str2)
{
    string result;
    int n1 = str1.length(), n2 = str2.length();
 
    // Compare str1 and str2
    for (int i=0, j=0; i<=n1-1&&j<=n2-1; i++,j++)
    {
        if (str1[i] != str2[j])
            break;
        result.push_back(str1[i]);
    }
 
    return (result);
}

"""
- at
- ataki(first)
- ate(first)
- ath
- athvithar(sound)
- athyolar(birth)
- cho
- chonge(solid)
- choo(pika)
- chori(eighty)
- e
- eve(tail)
- ewe(olive)
- ha
- haj(strong)
- hake(name)
- qa
- qaf(question)
- qazer(apple)
- v
- va
- vafi(lamb)
- vafikh(wool)
- valshe(north)
- vo
- vos(no)
- vov(weapon)
* /
"""
words = ["ataki(first)", "ate(first)", "ath", "athvithar(sound)", "athyolar(birth)", "chonge(solid)", "choo(pika)",
         "chori(eighty)", "eve(tail)", "ewe(olive)", "haj(strong)", "hake(name)", "qaf(question)", "qazer(apple)",
         "vafi(lamb)", "vafikh(wool)", "valshe(north)", "vos(no)", "vov(weapon)", "yours", "yo"]


def find_different_prefix(array):
    prefix_array = []
    array_length = len(array)
    for i in range(0, array_length):
        if i == len(array) - 1:
            if array[i] in prefix_array:
                break
            prefix_array.append(array[i])
            break
        current = array[i]
        next_word = array[i + 1]
        min_length = len(next_word) if len(current) > len(next_word) else len(current)
        prefix_index = 0
        while True:

            try:
                if current[prefix_index] == next_word[prefix_index] and min_length > prefix_index:
                    prefix_index += 1
                else:
                    print(current)
                    break
            except IndexError:
                if prefix_array.count(current[0:prefix_index-1]) == 0 and current[0:prefix_index] != "":
                    prefix_array.append(current[0:prefix_index-1])
                break
        if prefix_array.count(current[0:prefix_index]) == 0 and current[0:prefix_index] != "":
            prefix_array.append(current[0:prefix_index])
    return prefix_array


def group_by_prefix_array(prefix_array):
    result_array = []
    for i in prefix_array:
        temp_array = []
        for j in prefix_array:
            if i[0] == j[0]:
                temp_array.append(j)
        temp_array.sort()
        if result_array.count(temp_array) == 0:
            result_array.append(temp_array)
    return result_array


res = find_different_prefix(words)
stdout_group = group_by_prefix_array(res)

for group_array in stdout_group:
    if type(group_array) == list:
        for prefix_string_index in range(0, len(group_array)):
            print(prefix_string_index * "\t" + f"-{group_array[prefix_string_index]}")
            w_con = False
            child_con = True
            for k in words:
                if group_array[prefix_string_index] == k[0:len(group_array[prefix_string_index])]:
                    w_con = True
                else:
                    w_con = False
                if w_con:
                    if k in group_array and prefix_string_index == 0:
                        break
                    if prefix_string_index == 1 and group_array[prefix_string_index] == k:
                        pass
                    else:
                        print((prefix_string_index + 1) * "\t" + f"-{k}")

"""
count() == 0 için
    https://stackoverflow.com/questions/10376065/pushing-unique-data-into-vector
    
    std::vector<std::string> name;
    
    if (std::find(name.begin(), name.end(), someName) == name.end()) {
      // someName not in name, add it
      name.push_back(someName);
    }
    
sort() için
    https://www.geeksforgeeks.org/stdlistsort-c-stl/
    
    int main()
    {
    list<string> mylist = {"vafi", "va", "v", "vo"};
    mylist.sort();
    for (auto it = mylist.begin(); it != mylist.end(); ++it)
        cout << ' ' << *it;
    return 0;
    }
"""

#OUTPUT
"""
-at
        -ataki(first)
        -ate(first)
        -ath
                -athvithar(sound)
                -athyolar(birth)
-cho
        -chonge(solid)
        -choo(pika)
        -chori(eighty)
-e
        -eve(tail)
        -ewe(olive)
-ha
        -haj(strong)
        -hake(name)
-qa
        -qaf(question)
        -qazer(apple)
-v
        -vafi(lamb)
        -vafikh(wool)
        -valshe(north)
        -vos(no)
        -vov(weapon)
        -va
                -vafi(lamb)
                -vafikh(wool)
                -valshe(north)
                -vafi
                        -vafi(lamb)
                        -vafikh(wool)
                        -vo
                                -vos(no)
                                -vov(weapon)

"""

*/