/*For Facebook Software Engineering Internship Interview Preparation */
/* %%%%%%%%%%%%%%%%%%% ALL SUBSETS %%%%%%%%%%%%%%%%%%%%%%% */

ArrayList<ArrayList<Integer>> getSubsets2(ArrayList<Integer> set) {
	ArrayList<ArrayList<Integer>> allsubsets =
	new ArrayList<ArrayList<Integer>>();
	int max = 1 « set.sizeQ; /* Compute 2^n */
	for (int k = 0; k < max; k++) {
		ArrayList<Integer> subset = convertIntToSet(k, set);
		allsubsets.add(subset);
	}
	return allsubsets;
}

ArrayList<Integer> convertIntToSet(int x, ArrayList<Integer> set) {
	ArrayList<Integer> subset = new ArrayList<Integer>();
	int index = 0;

	for (int k = x; k > 0; k »= 1) {
		if ((k & 1) == 1) {
			subset. add(set.get(index));
		}
		index++;
	}
	return subset;
}

%%%%%%%%%%%%%%%%%%% NUMBER OF 2s %%%%%%%%%%%%%%%%%%%%%%%

public static int count2sInRangeAtDigit(int number, int d) {
	int powerOflO = (int) Math.pow(10, d);
	int nextPowerOf10 = powerOf10 * 10;
	int right = number % powerOfl0;

	int roundDown = number - number % nextPowerOflO;
	int roundup = roundDown + nextPowerOflO;

	int digit = (number / powerOf10) % 10;
	if (digit < 2) { // if the digit in spot digit is
		return roundDown / 10;
	} else if (digit == 2) {
		return roundDown / 10 + right + 1;
	} else {
		return roundUp / 10;
	}
}

public static int count2sInRange(int number) {
	int count = 0;
	int len = String.valueOf(number).length();
	for (int digit = 0; digit < len; digit++) {
		count += count2sInRangeAtDigit(number, digit);
	}
	return count;
}



%%%%%%%%%%%%%%%%%%% ALL VALID n-PARANTHESIS %%%%%%%%%%%%%%%%%%%%%%%

void _printParenthesis(int pos, int n, int open, int close)
{
    static char str[MAX_SIZE];   
     
    if(close == n) 
    {
        printf("%s \n", str);
        return;
    }
    else
    {
        if(open > close) 
        {
            str[pos] = '}';
            _printParenthesis(pos+1, n, open, close+1);
        }
         
        if(open < n)
        {
        str[pos] = '{';
        _printParenthesis(pos+1, n, open+1, close);
        }
    }
}

%%%%%%%%%%%%%%%%%%% REVERSE LINKED LIST RECURSIVE %%%%%%%%%%%%%%%%%%%%%%%

void recursiveReverse(struct Node** head_ref)
{
    struct Node* first;
    struct Node* rest;
      
    /* empty list */
    if (*head_ref == NULL)
       return;   
 
    /* suppose first = {1, 2, 3}, rest = {2, 3} */
    first = *head_ref;  
    rest  = first->next;
 
    /* List has only one node */
    if (rest == NULL)
       return;   
 
    /* reverse the rest list and put the first element at the end */
    recursiveReverse(&rest);
    first->next->next  = first;  
     
    /* tricky step -- see the diagram */
    first->next  = NULL;          
 
    /* fix the head pointer */
    *head_ref = rest;              
}

%%%%%%%%%%%%%%%%%%% IS SUBTREE %%%%%%%%%%%%%%%%%%%%%%%

/* A utility function to check whether trees with roots as root1 and
   root2 are identical or not */
bool areIdentical(struct node * root1, struct node *root2)
{
    /* base cases */
    if (root1 == NULL && root2 == NULL)
        return true;
 
    if (root1 == NULL || root2 == NULL)
        return false;
 
    /* Check if the data of both roots is same and data of left and right
       subtrees are also same */
    return (root1->data == root2->data   &&
            areIdentical(root1->left, root2->left) &&
            areIdentical(root1->right, root2->right) );
}
 
 
/* This function returns true if S is a subtree of T, otherwise false */
bool isSubtree(struct node *T, struct node *S)
{
    /* base cases */
    if (S == NULL)
        return true;
 
    if (T == NULL)
        return false;
 
    /* Check the tree with root as current node */
    if (areIdentical(T, S))
        return true;
 
    /* If the tree with root as current node doesn't match then
       try left and right subtrees one by one */
    return isSubtree(T->left, S) ||
           isSubtree(T->right, S);
}



%%%%%%%%%%%%%%%%%%% BST TO MIN-HEAP %%%%%%%%%%%%%%%%%%%%%%%


void BSTToSortedLL(Node* root, Node** head_ref)
{
    // Base cases
    if(root == NULL)
        return;
 
    // Recursively convert right subtree
    BSTToSortedLL(root->right, head_ref);
 
    // insert root into linked list
    root->right = *head_ref;
 
    // Change left pointer of previous head
    // to point to NULL
    if (*head_ref != NULL)
        (*head_ref)->left = NULL;
 
    // Change head of linked list
    *head_ref = root;
 
    // Recursively convert left subtree
    BSTToSortedLL(root->left, head_ref);
}
 
// Function to convert a sorted Linked
// List to Min-Heap.
// root --> Root of Min-Heap
// head --> Pointer to head node of sorted
//              linked list
void SortedLLToMinHeap(Node* &root, Node* head)
{
    // Base Case
    if (head == NULL)
        return;
 
    // queue to store the parent nodes
    queue<Node *> q;
 
    // The first node is always the root node
    root = head;
 
    // advance the pointer to the next node
    head = head->right;
 
    // set right child to NULL
    root->right = NULL;
 
    // add first node to the queue
    q.push(root);
 
    // run until the end of linked list is reached
    while (head)
    {
        // Take the parent node from the q and remove it from q
        Node* parent = q.front();
        q.pop();
 
        // Take next two nodes from the linked list and
        // Add them as children of the current parent node
        // Also in push them into the queue so that
        // they will be parents to the future nodes
        Node *leftChild = head;
        head = head->right;        // advance linked list to next node
        leftChild->right = NULL; // set its right child to NULL
        q.push(leftChild);
 
        // Assign the left child of parent
        parent->left = leftChild;
 
        if (head)
        {
            Node *rightChild = head;
            head = head->right; // advance linked list to next node
            rightChild->right = NULL; // set its right child to NULL
            q.push(rightChild);
 
            // Assign the right child of parent
            parent->right = rightChild;
        }
    }
}
 
// Function to convert BST into a Min-Heap
// without using any extra space
Node* BSTToMinHeap(Node* &root)
{
    // head of Linked List
    Node *head = NULL;
 
    // Convert a given BST to Sorted Linked List
    BSTToSortedLL(root, &head);
 
    // set root as NULL
    root = NULL;
 
    // Convert Sorted Linked List to Min-Heap
    SortedLLToMinHeap(root, head);
}

%%%%%%%%%%%%%%%%%%% PERMUTATIONS %%%%%%%%%%%%%%%%%%%%%%%


void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int l, int r)
{
   int i;
   if (l == r)
     printf("%sn", a);
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }

   
%%%%%%%%%%%%%%%%%%% VALIDATE BST %%%%%%%%%%%%%%%%%%%%%%%

bool isBST(Node* root, Node* &prev)
{
    // base case: empty tree is a BST
	if (root == nullptr)
		return true;

    // check if left subtree is BST or not
	bool left = isBST(root->left, prev);

	// value of current node should be more than that of previous node
	if (prev != NULL && root->data <= prev->data)
		return false;

    // update previous node and check if right subtree is BST or not
	prev = root;
	return left && isBST(root->right, prev);
}

// Function to determine if given Binary Tree is a BST or not
void isBST(Node* node)
{
    // pointer to store previous processed node in inorder traversal
	Node* prev = newNode(INT_MIN);

	// check if nodes are nodes are processed in sorted order
	if (isBST(node, prev))
        printf("This is a BST.");
    else
        printf("This is NOT a BST!");
}

%%%%%%%%%%%%%%%%%%% SQUARE ROOT %%%%%%%%%%%%%%%%%%%%%%%

/*Returns the square root of n. Note that the function */
float squareRoot(float n)
{
  /*We are using n itself as initial approximation
   This can definitely be improved */
  float x = n;
  float y = 1;
  float e = 0.000001; /* e decides the accuracy level*/
  while(x - y > e)
  {
    x = (x + y)/2;
    y = n/x;
  }
  return x;
}

%%%%%%%%%%%%%%%%%%% EXPONENTIATION %%%%%%%%%%%%%%%%%%%%%%%

int ipow(int base, int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

%%%%%%%%%%%%%%%%%%% SORT STACK ITERATIVE %%%%%%%%%%%%%%%%%%%%%%%

void SortStack(struct Stack * orig_stack)
{
  struct Stack helper_stack;
  while (!IsEmpty(orig_stack))
  {
    int element = Pop(orig_stack);
    while (!IsEmpty(&helper_stack) && Top(&helper_stack) < element)
    {
      Push(orig_stack, Pop(&helper_stack));
    }
    Push(&helper_stack, element);
  }
  while (!IsEmpty(&helper_stack))
  {
    Push(orig_stack, Pop(&helper_stack));
  }
}


%%%%%%%%%%%%%%%%%%% SORT STACK RECURSIVE %%%%%%%%%%%%%%%%%%%%%%%

// Recursive function to insert an item x in sorted way
void sortedInsert(struct stack **s, int x)
{
    // Base case: Either stack is empty or newly inserted
    // item is greater than top (more than all existing)
    if (isEmpty(*s) || x > top(*s))
    {
        push(s, x);
        return;
    }
 
    // If top is greater, remove the top item and recur
    int temp = pop(s);
    sortedInsert(s, x);
 
    // Put back the top item removed earlier
    push(s, temp);
}
 
// Function to sort stack
void sortStack(struct stack **s)
{
    // If stack is not empty
    if (!isEmpty(*s))
    {
        // Remove the top item
        int x = pop(s);
 
        // Sort remaining stack
        sortStack(s);
 
        // Push the top item back in sorted stack
        sortedInsert(s, x);
    }
}

%%%%%%%%%%%%%%%%%%%% PRINT LEAFNODES FROM PRE-ORDER OF BST %%%%%%%%%%%%%%%%%%%%%%%

void leafNode(int preorder[], int n)
{
    stack<int> s;
    for (int i = 0, j = 1; j < n; i++, j++)
    {
        bool found = false;
 
        if (preorder[i] > preorder[j])
            s.push(preorder[i]);
 
        else
        {
            while (!s.empty())
            {
                if (preorder[j] > s.top())
                {
                    s.pop();
                    found = true;
                }
                else
                    break;
            }
        }
 
        if (found)
            cout << preorder[i] << " ";
    }
 
    // Since rightmost element is always leaf node.
    cout << preorder[n - 1];
}

%%%%%%%%%%%%%%%%%%%% SORTED ARRAY TO BST %%%%%%%%%%%%%%%%%%%%%%%

struct TNode* sortedArrayToBST(int arr[], int start, int end)
{
    /* Base Case */
    if (start > end)
      return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    struct TNode *root = newNode(arr[mid]);
 
    /* Recursively construct the left subtree and make it
       left child of root */
    root->left =  sortedArrayToBST(arr, start, mid-1);
 
    /* Recursively construct the right subtree and make it
       right child of root */
    root->right = sortedArrayToBST(arr, mid+1, end);
 
    return root;
}

%%%%%%%%%%%%%%%%%%%% SORTED LINKED LIST TO BST %%%%%%%%%%%%%%%%%%%%%%%

struct TNode* sortedListToBST(struct LNode *head)
{
    /*Count the number of nodes in Linked List */
    int n = countLNodes(head);
 
    /* Construct BST */
    return sortedListToBSTRecur(&head, n);
}
 
/* The main function that constructs balanced BST and returns root of it.
       head_ref -->  Pointer to pointer to head node of linked list
       n  --> No. of nodes in Linked List */
struct TNode* sortedListToBSTRecur(struct LNode **head_ref, int n)
{
    /* Base Case */
    if (n <= 0)
        return NULL;
 
    /* Recursively construct the left subtree */
    struct TNode *left = sortedListToBSTRecur(head_ref, n/2);
 
    /* Allocate memory for root, and link the above constructed left 
       subtree with root */
    struct TNode *root = newNode((*head_ref)->data);
    root->left = left;
 
    /* Change head pointer of Linked List for parent recursive calls */
    *head_ref = (*head_ref)->next;
 
    /* Recursively construct the right subtree and link it with root 
      The number of nodes in right subtree  is total nodes - nodes in 
      left subtree - 1 (for root) which is n-n/2-1*/
    root->right = sortedListToBSTRecur(head_ref, n-n/2-1);
 
    return root;
}

%%%%%%%%%%%%%%%%%%%% NUMBER OF WAYS TO CLIMB STAIRS %%%%%%%%%%%%%%%%%%%%%%%

int countWaysUtil(int n, int m)
{
    int res[n];
    res[0] = 1; res[1] = 1;
    for (int i=2; i<n; i++)
    {
       res[i] = 0;
       for (int j=1; j<=m && j<=i; j++)
         res[i] += res[i-j];
    }
    return res[n-1];
}
 
// Returns number of ways to reach s'th stair
int countWays(int s, int m)
{
    return countWaysUtil(s+1, m);
}

%%%%%%%%%%%%%%%%%%%% HEAPSORT AND MAKE HEAP %%%%%%%%%%%%%%%%%%%%%%%

def heapsort( aList ):
  # convert aList to heap
  length = len( aList ) - 1
  leastParent = length / 2
  for i in range ( leastParent, -1, -1 ):
    moveDown( aList, i, length )
 
  # flatten heap into sorted array
  for i in range ( length, 0, -1 ):
    if aList[0] > aList[i]:
      swap( aList, 0, i )
      moveDown( aList, 0, i - 1 )
 
 
def moveDown( aList, first, last ):
  largest = 2 * first + 1
  while largest <= last:
    # right child exists and is larger than left child
    if ( largest < last ) and ( aList[largest] < aList[largest + 1] ):
      largest += 1
 
    # right child is larger than parent
    if aList[largest] > aList[first]:
      swap( aList, largest, first )
      # move down to largest child
      first = largest;
      largest = 2 * first + 1
    else:
      return # force exit
 
 
def swap( A, x, y ):
  tmp = A[x]
  A[x] = A[y]
  A[y] = tmp
	 
	  
/* %%%%%%%%%%%%%%%%%%% BASE 10 TO BASE 7 ATLASSIAN %%%%%%%%%%%%%%%%%%%%%%% */

/* 
Gives output of 7 as: a0   
Gives output of 7792875 as atlassian   
*/
public static void main(String[] args) {

        char [] b7={'0','a', 't', 'l', 's', 'i', 'n'};
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();

        int i=t;
        StringBuffer sb = new StringBuffer();
        while (i>0){
            int m=i%7;
            sb.append(b7[m]);
            i=i/7;
        }

        System.out.println(sb.reverse());
        in.close();

    }

/* %%%%%%%%%%%%%%%%%%% CONVERT FLOAT NUMBER TO STRING %%%%%%%%%%%%%%%%%%%%%%% */
 
// reverses a string 'str' of length 'len'
void reverse(char *str, int len)
{
    int i=0, j=len-1, temp;
    while (i<j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++; j--;
    }
}
 
 // Converts a given integer x to string str[].  d is the number
 // of digits required in output. If d is more than the number
 // of digits in x, then 0s are added at the beginning.
int intToStr(int x, char str[], int d)
{
    int i = 0;
    while (x)
    {
        str[i++] = (x%10) + '0';
        x = x/10;
    }
 
    // If number of digits required is more, then
    // add 0s at the beginning
    while (i < d)
        str[i++] = '0';
 
    reverse(str, i);
    str[i] = '\0';
    return i;
}
 
// Converts a floating point number to string.
void float_to_string(float n, char *res, int afterpoint)
{
    // Extract integer part
    int ipart = (int)n;
 
    // Extract floating part
    float fpart = n - (float)ipart;
 
    // convert integer part to string
    int i = intToStr(ipart, res, 0);
 
    // check for display option after point
    if (afterpoint != 0)
    {
        res[i] = '.';  // add dot
 
        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter is needed
        // to handle cases like 233.007
        fpart = fpart * pow(10, afterpoint);
 
        intToStr((int)fpart, res + i + 1, afterpoint);
    }
}

/* %%%%%%%%%%%%%%%%%%% CONVERT STRING TO FLOATING POINT NUMBER %%%%%%%%%%%%%%%%%%%%%%% */
double atof(char* num)
 {
     if (!num || !*num)
         return 0; 
     double integerPart = 0;
     double fractionPart = 0;
     int divisorForFraction = 1;
     int sign = 1;
     bool inFraction = false;
     /*Take care of +/- sign*/
     if (*num == '-')
     {
         ++num;
         sign = -1;
     }
     else if (*num == '+')
     {
         ++num;
     }
     while (*num != '\0')
     {
         if (*num >= '0' && *num <= '9')
         {
             if (inFraction)
             {
                 /*See how are we converting a character to integer*/
                 fractionPart = fractionPart*10 + (*num - '0');
                 divisorForFraction *= 10;
             }
             else
             {
                 integerPart = integerPart*10 + (*num - '0');
             }
         }
         else if (*num == '.')
         {
             if (inFraction)
                 return sign * (integerPart + fractionPart/divisorForFraction);
             else
                 inFraction = true;
         }
         else
         {
             return sign * (integerPart + fractionPart/divisorForFraction);
         }
         ++num;
     }
     return sign * (integerPart + fractionPart/divisorForFraction);
 }
/* Next smaller number formed from the same digits */
def findNext(number,n):
     # Start from the right most digit and find the first
     # digit that is smaller than the digit next to it
     for i in range(n-1,0,-1):
         if number[i] < number[i-1]:
             break
              
     # If no such digit found,then all numbers are in 
     # descending order, no greater number is possible
     if i == 0:
         print "Next number not possible"
         return
          
     # Find the smallest digit on the right side of 
     # (i-1)'th digit that is greater than number[i-1]
     x = number[i-1]
     largest = i
     for j in range(i+1,n):
         if number[j] < x and number[j] > number[largest]:
             largest = j
          
     # Swapping the above found smallest digit with (i-1)'th
     number[largest],number[i-1] = number[i-1], number[largest]
      
     # X is the final number, in integer datatype 
     x = 0
     # Converting list upto i-1 into number
     for j in range(i):
         x = x * 10 + number[j]
      
     # Sort the digits after i-1 in descending order
     number = sorted(number[i:]).reverse()
     # converting the remaining sorted digits into number
     for j in range(n-i):
         x = x * 10 + number[j]
      
     print "Next number with set of digits is",x
 
		 def findNext(number,n):
      
     # Start from the right most digit and find the first
     # digit that is smaller than the digit next to it
     for i in range(n-1,0,-1):
         if number[i] > number[i-1]:
             break
              
     # If no such digit found,then all numbers are in 
     # descending order, no greater number is possible
     if i == 0:
         print "Next number not possible"
         return
          
     # Find the smallest digit on the right side of 
     # (i-1)'th digit that is greater than number[i-1]
     x = number[i-1]
     smallest = i
     for j in range(i+1,n):
         if number[j] > x and number[j] < number[smallest]:
             smallest = j
          
     # Swapping the above found smallest digit with (i-1)'th
     number[smallest],number[i-1] = number[i-1], number[smallest]
      
     # X is the final number, in integer datatype 
     x = 0
     # Converting list upto i-1 into number
     for j in range(i):
         x = x * 10 + number[j]
      
     # Sort the digits after i-1 in ascending order
     number = sorted(number[i:])
     # converting the remaining sorted digits into number
     for j in range(n-i):
         x = x * 10 + number[j]
      
     print "Next number with set of digits is",x

/* Next larger number formed from the same digits */		 
def findNext(number,n):
      
     # Start from the right most digit and find the first
     # digit that is smaller than the digit next to it
     for i in range(n-1,0,-1):
         if number[i] > number[i-1]:
             break
              
     # If no such digit found,then all numbers are in 
     # descending order, no greater number is possible
     if i == 0:
         print "Next number not possible"
         return
          
     # Find the smallest digit on the right side of 
     # (i-1)'th digit that is greater than number[i-1]
     x = number[i-1]
     smallest = i
     for j in range(i+1,n):
         if number[j] > x and number[j] < number[smallest]:
             smallest = j
          
     # Swapping the above found smallest digit with (i-1)'th
     number[smallest],number[i-1] = number[i-1], number[smallest]
      
     # X is the final number, in integer datatype 
     x = 0
     # Converting list upto i-1 into number
     for j in range(i):
         x = x * 10 + number[j]
      
     # Sort the digits after i-1 in ascending order
     number = sorted(number[i:])
     # converting the remaining sorted digits into number
     for j in range(n-i):
         x = x * 10 + number[j]
      
     print "Next number with set of digits is",x
