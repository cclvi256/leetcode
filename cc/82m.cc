#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head) {
  if (head && head->next) {
    bool first = true;
    ListNode *curr = nullptr;
    ListNode *res = nullptr;

    bool duplicated = false;
    int duplicate = 0;

    while (head) {
      if (duplicated) {
        if (head->val == duplicate) {
          head = head->next;
        } else {
          duplicated = false;
        }
        continue;
      }

      if (head->next && head->val == head->next->val) {
        duplicated = true;
        duplicate = head->val;
      } else {
        if (first) {
          res = curr = new ListNode(head->val);
          first = false;
        } else {
          curr->next = new ListNode(head->val);
          curr = curr->next;
        }
        head = head->next;
      }
    }

    return res;
  } else if (head) {
    return head;
  } else {
    return nullptr;
  }
}

int main(int argc, char **argv) {
  // Create a linked list from user input
  std::cout << "Enter the elements of the linked list (enter -1 to stop): ";
  int num;
  std::vector<int> nums;
  while (std::cin >> num && num != -1) {
    nums.push_back(num);
  }

  // Create the linked list
  ListNode *head = nullptr;
  ListNode *tail = nullptr;
  for (int num : nums) {
    ListNode *newNode = new ListNode(num);
    if (head == nullptr) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  // Call the deleteDuplicates function
  ListNode *result = deleteDuplicates(head);

  // Print the resulting linked list
  std::cout << "Resulting linked list: ";
  ListNode *curr = result;
  while (curr != nullptr) {
    std::cout << curr->val << " ";
    curr = curr->next;
  }
  std::cout << std::endl;

  // Clean up the linked list
  curr = result;
  while (curr != nullptr) {
    ListNode *temp = curr;
    curr = curr->next;
    delete temp;
  }

  return 0;
}