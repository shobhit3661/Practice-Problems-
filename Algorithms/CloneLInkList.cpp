#include<bits/stdc++.h>
#define fast  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long int ll;

using namespace std;
class ALNode
{
	public:
		int value;
		ALNode *next;
		ALNode *arbitray;
		
		ALNode(int val)
		{
			this->value = val;
			this->next = NULL;
			this->arbitray = NULL;
		}
		
		ALNode()
		{
			this->value = -1;
			this->next = NULL;
			this->arbitray = NULL;
		}
};

void print(ALNode *start) 
{ 
	ALNode *ptr = start; 
	while (ptr) 
	{ 
		cout << "Data = " << ptr->value << ", Random = "
			<< ptr->arbitray->value << endl; 
		ptr = ptr->next; 
	} 
} 

ALNode* DeepCopy(ALNode *head) 
{ 
    ALNode* curr = head, *temp; 
    while (curr) 
    { 
        temp = curr->next; 
        curr->next = new ALNode(curr->value); 
        curr->next->next = temp; 
        curr = temp; 
    } 
  
    curr = head; 
    while (curr) 
    { 
        if(curr->next) 
            curr->next->arbitray = curr->arbitray ?  
                                 curr->arbitray->next : curr->arbitray; 
        curr = curr->next?curr->next->next:curr->next; 
    } 
  
    ALNode* original = head, *copy = head->next; 
    temp = copy; 
    while (original && copy) 
    { 
        original->next = 
         original->next? original->next->next : original->next; 
  
        copy->next = copy->next?copy->next->next:copy->next; 
        original = original->next; 
        copy = copy->next; 
    } 
  
    return temp; 
} 
int main() 
{ 
    ALNode *start = new ALNode(1); 
    start->next = new ALNode(2); 
    start->next->next = new ALNode(3); 
    start->next->next->next = new ALNode(4); 
    start->next->next->next->next = new ALNode(5); 
  
    start->arbitray = start->next->next; 
    start->next->arbitray = start; 
    start->next->next->arbitray = 
                    start->next->next->next->next; 
    start->next->next->next->arbitray = 
                    start->next->next->next->next; 
    start->next->next->next->next->arbitray = 
                                      start->next; 
  
    cout << "Original list : \n"; 
    print(start); 
  
    cout << "\nCloned list : \n"; 
    ALNode *cloned_list = DeepCopy(start); 
    print(cloned_list); 
  
    return 0; 
} 

