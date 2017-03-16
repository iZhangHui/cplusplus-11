struct ListNode {
int value;
struct ListNode* next;
};

ListNode* revert_list(ListNode* head)
{
	ListNode* prev = nullptr;
	ListNode* next = nullptr;

	while (head) {
		// hanle current node
		next = head->next;
		head->next = prev;

		// move to next node
		prev = head;
		head = next;
	}

	return prev;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}