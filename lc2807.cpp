#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* insertGreatestCommonDivisors(ListNode* head);
int GCD(int a, int b);

int main(int argc, char** argv) {
  // Get user input
  int n;
  cout << "Enter the number of elements: ";
  cin >> n;

  // Create the linked list
  ListNode* head = nullptr;
  ListNode* tail = nullptr;
  for (int i = 0; i < n; i++) {
    int val;
    cout << "Enter element " << i + 1 << ": ";
    cin >> val;

    ListNode* newNode = new ListNode(val);
    if (head == nullptr) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  // Call the function
  ListNode* result = insertGreatestCommonDivisors(head);

  // Print the modified linked list
  ListNode* current = result;
  while (current != nullptr) {
    cout << current->val << " ";
    current = current->next;
  }
  cout << endl;

  // Clean up the memory
  current = result;
  while (current != nullptr) {
    ListNode* temp = current;
    current = current->next;
    delete temp;
  }

  return 0;
}

ListNode* insertGreatestCommonDivisors(ListNode* head) {
  ListNode* copy = head;

  while (copy->next != nullptr) {
    int gcd = GCD(copy->val, copy->next->val);
    ListNode* temp = new ListNode(gcd, copy->next);
    copy->next = temp;
    copy = copy->next->next;
  }

  return head;
}

int GCD(int a, int b) {
  if (b) {
    while ((a %= b) && (b %= a))
      ;
    return a + b;
  }
  return 0;
}
