// Geek has developed an effective vaccine for Corona virus and he wants each of the N houses in Geek Land to have access to it. Given a binary tree where each node represents a house in Geek Land, find the minimum number of houses that should be supplied with the vaccine kit if one vaccine kit is sufficient for that house, its parent house and it's immediate child nodes.  

 

// Example :

// Input:
//     1
//    / \
//   2   3 
//         \
//          4
//           \
//            5
//             \
//              6

// Output:
// 2
// Explanation:
// The vaccine kits should be 
// supplied to house numbers 1 and 5. 

//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) 
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

 // } Driver Code Ends


//User function Template for C++

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution{
public:
int vaccine;
    int supplyVaccine(Node* root){
       vaccine=0; 
       pair<bool,bool> temp = tovaccine(root); 
       if(!temp.second){ 
           vaccine++; 
       }
return vaccine; 
}
  pair<bool,bool> tovaccine(Node* root)
  { if(root==NULL){ 
      return {false,true}; 
      }
pair<bool,bool> Left = tovaccine(root->left); 
pair<bool,bool> Right = tovaccine(root->right); 

bool has_vaccine = false; 
bool vaccinated = false; 

if(Left.first || Right.first){ 
    vaccinated = true; 
}
if(!Left.second || !Right.second){
    has_vaccine = true; 
    vaccinated = true; 
    vaccine++; 
    
} 
return {has_vaccine,vaccinated}; 
    }
};

// { Driver Code Starts.
int main() 
{
    int t;
    scanf("%d ", &t);
    while (t--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout<<ob.supplyVaccine(root)<<"\n";
    }
    return 0;
}



  // } Driver Code Ends