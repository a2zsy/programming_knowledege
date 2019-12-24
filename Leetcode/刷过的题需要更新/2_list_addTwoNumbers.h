//逆序对list提前补零，用链表实现逆序存储的数的加法

/*给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//对长度不一的链表补零
		int len1 = 1;
		int len2 = 1;
		ListNode* p = l1;
		ListNode* q = l2;
		while (p->next != NULL)
		{
			len1++;
			p = p->next;
		}
		while (q->next != NULL)
		{
			len2++;
			q = q->next;
		}
		if (len1 > len2)
		{
			for (auto i = 1; i <= len1 - len2; i++)
			{
				q->next = new ListNode(0);
				q = q->next;
			}

		}
		else {
			for (auto i = 1; i <= len2 - len1; i++)
			{
				p->next = new ListNode(0);
				p = p->next;

			}

		}
		//预处理完毕，正式开始加减
		p = l1;
		q = l2;
		bool count = false;
		ListNode* l3 = new ListNode(0);
		ListNode* w = l3;
		while (p != NULL && q != NULL)
		{
			int i = count + p->val + q->val;
			w->next = new ListNode(i % 10);
			count = i >= 10 ? true : false;
			w = w->next;
			p = p->next;
			q = q->next;
		}
		if (count)
		{
			w->next = new ListNode(1);
			w = w->next;
		}

		return l3->next;
	}
};

