#include <iostream>
using namespace std;

string longestPalindrome2(string s) {
    if(s.length() == 1 || s.empty())
        return s;
    if(s.length() == 2) {
        if(s[0] == s[1])
            return s;
        else 
            return s.substr(0,1);
    }
    string res;
    int max_length = 0;
    for(string::iterator start = s.begin() + 1; start!=s.end()-1; ++start) {
        string sub;
        sub += *start;
        cout << "start: " << sub << endl;
        string::iterator head = start;
        string::iterator tail = start;

        int length = 1;
        if(start - 1 == s.begin()) {
            if(*(start-1) == *start) {
                ++length;
                sub += *start;
                --head;
            }
        }
        for(string::iterator left = start - 1; left != s.begin(); left--) {
            if(*left == *start) {
                ++length;
                sub += *start;
                --head;
                if(left - 1 == s.begin()) {
                    if(*(left-1) == *start) {
                        ++length;
                        sub += *start;
                        --head;
                    }
                }
            } else {
                break;
            }
        }
        
        for(string::iterator right = start + 1; right != s.end(); right++) {
            if(*right == *start) {
                ++length;
                sub += *start;
                ++tail;
            } else {
                break;
            }
        }
        cout << "merged: " << sub << endl;
        /*
        if(*start == *(start-1) && *start == *(start+1)) {
            head -= 1;
            tail += 1;
            length += 2;
            sub+=*start;
            sub+=*start;
            if(head == s.begin() || tail == s.end()-1) {
                if(length > max_length) {
                    res = sub;
                    max_length = length;
                }
                continue;
            }
        } else if(*(start-1) == *start) {
            head -= 1;
            ++length;
            sub += *start;
            cout << sub << endl;
            if(head == s.begin()) {
                if(length > max_length) {
                    res = sub;
                    max_length = length;
                }
                continue;
            }
        } else if(*(start+1) == *start) {
            tail += 1;
            ++length;
            sub += *start;
            if(tail == s.end()-1) {
                if(length > max_length) {
                    res = sub;
                    max_length = length;
                }
                continue;
            }
        } 
        */
        if(head == s.begin() || tail == s.end()-1) {
            if(length > max_length) {
                res = sub;
                max_length = length;
            }
            continue;
        }        
        head--;
        tail++;
        cout << *head << ", " << *tail << endl;
        if(head == s.begin() || tail == s.end()-1) {
            if(*head == *tail) {
                length += 2;
                sub.insert(sub.begin(),*head);
                sub += *head;
               cout << "find2: " << sub << endl;

            }
            if(length > max_length) {
                res = sub;
                max_length = length;
            }
            continue;
        }
        
        for(; head!=s.begin() && tail != s.end(); --head, ++tail) {
            if(*head == *tail) {
                length += 2;
                sub.insert(sub.begin(),*head);
                sub += *head;
                cout << "find: " << sub << endl;
                if(head - 1 == s.begin() && tail + 1 != s.end()) {
                    if(*(head-1) == *(tail+1)) {
                        length +=2 ;
                        sub.insert(sub.begin(),*(head-1));
                        sub += *(head-1);
                        if(length > max_length) {
                            res = sub;
                            max_length = length;
                        }

                        break;
                    }
                } 
            } else {
                break;
            }
        }

        if(length > max_length) {
            res = sub;
            max_length = length;
        }
    }
    cout << "res: ";
    return res;
}
string longestPalindrome(string s) {
    if(s.length() == 1 || s.empty())
        return s;
    int max_length = 0;
    string res;
    int flag = 0;
    int string_length = s.length();
    for(string::iterator start = s.begin(); start != s.end(); ++start) {
        if(s.end() - start <= max_length) {
            break;
        }
        for(string::iterator end = s.end() - 1; end!=start; --end) {
        
            int length = 0;
            bool find_flag = false;
            string sub;
            //cout << *start << " " << *end << endl;
             for(string::iterator sub_head = start, sub_tail = end; sub_head!=sub_tail; ++sub_head, --sub_tail) {
               //cout << *sub_head << ", " << *sub_tail << endl;
                if(*sub_head == *sub_tail) {
                    ++length;
                    sub += *sub_head;
        
                    if(sub_head+1 == sub_tail) {
                        find_flag = true;
                        length *= 2;
                        if(length > max_length) {
                            max_length = length;
                            res = sub;
                            flag = 1;
                        }
                        break;
                    } else if (sub_head + 1 == sub_tail - 1) {
                        find_flag = true;
                        length = length*2 + 1;
                        if(length > max_length) {
                            max_length = length;
                            res = sub + *(sub_head+1);
                            flag = 2;
                        }
                        break;
                    }
                } else {
                    break;
                }
            }
            if(find_flag) {
                break;
            }
        }
        
    }
    if(flag == 0)
        return s.substr(0,1);
    string palindrom = res;
    for(string::iterator it = res.end()-flag; it!=res.begin(); --it) {
        palindrom += *it;
    }
    palindrom += res[0];

    return palindrom;
}
int main () {
    cout <<  longestPalindrome2("ac") << endl;
}