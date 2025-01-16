#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
  if (head != nullptr) {
    ListNode* res = nullptr;
    ListNode* curr = nullptr;

    while (head->next != nullptr) {
      if (head->val != head->next->val) {
        if (res == nullptr) {
          res = curr = new ListNode(head->val);
        } else {
          curr->next = new ListNode(head->val);
          curr = curr->next;
        }
      }
      head = head->next;
    }

    if (curr) {
      curr->next = new ListNode(head->val);
    } else {
      res = new ListNode(head->val);
    }

    return res;
  } else {
    return nullptr;
  }
}

int main(int argc, char** argv) {
  // Test case for deleteDuplicates function
  ListNode* head = nullptr;
  ListNode* tail = nullptr;

  // Get input from the user
  int n;
  std::cout << "Enter the number of elements: ";
  std::cin >> n;

  std::cout << "Enter the elements: ";
  for (int i = 0; i < n; i++) {
    int val;
    std::cin >> val;

    ListNode* newNode = new ListNode(val);
    if (head == nullptr) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  // Call the deleteDuplicates function
  ListNode* result = deleteDuplicates(head);

  // Print the result
  std::cout << "Result: ";
  ListNode* current = result;
  while (current != nullptr) {
    std::cout << current->val << " ";
    current = current->next;
  }
  std::cout << std::endl;

  // Clean up the memory
  current = result;
  while (current != nullptr) {
    ListNode* temp = current;
    current = current->next;
    delete temp;
  }

  return 0;
}
