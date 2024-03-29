#ifndef _NTFS_LIST_H
#define _NTFS_LIST_H

struct list_head {
		    struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
		    struct list_head name = LIST_HEAD_INIT(name)

#define INIT_LIST_HEAD(ptr) do { \
		    (ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)

/*功能：就是把new节点插入到prev和next之间,插入后则变成:prev->new->next*/
/*比如prev是head节点，next是head指向的第一个节点.则需要做如下操作
 *1) 把new的prev指向head节点,new的next指向next.
 *2) 把根节点的next指向new
 *3) 把next的prev指向new
 */
static __inline__ void __list_add(struct list_head * new,
					struct list_head * prev, struct list_head * next)
{
		    next->prev = new;
		    new->next = next;
		    new->prev = prev;
		    prev->next = new;
}

/*功能：把new节点，插入到head之后.
* head->next:head指向的第一个数据节点.
 */
static __inline__ void list_add(struct list_head *new, struct list_head *head)
{
		    __list_add(new, head, head->next);
}

/*功能：把new节点，插入到head链表中最后一个节点后。
* head->prev:head指向的最后一个数据节点.
 */
static __inline__ void list_add_tail(struct list_head *new, struct list_head *head)
{
		    __list_add(new, head->prev, head);
}

static __inline__ void __list_del(struct list_head * prev,
					struct list_head * next)
{
		    next->prev = prev;
		    prev->next = next;
}

static __inline__ void list_del(struct list_head *entry)
{
		    __list_del(entry->prev, entry->next);
}

static __inline__ void list_del_init(struct list_head *entry)
{
		    __list_del(entry->prev, entry->next);
		    INIT_LIST_HEAD(entry);
}


static __inline__ int list_empty(struct list_head *head)
{
		    return head->next == head;
}


static __inline__ void list_splice(struct list_head *list,
					struct list_head *head)
{
		    struct list_head *first = list->next;

		    if (first != list) {
					struct list_head *last = list->prev;
					struct list_head *at = head->next;

					first->prev = head;
					head->next = first;

					last->next = at;
					at->prev = last;
		    }
}


#define list_entry(ptr, type, member) \
		    ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))

#define list_for_each(pos, head) \
		    for (pos = (head)->next; pos != (head); pos = pos->next)

#define list_for_each_safe(pos, n, head) \
		    for (pos = (head)->next, n = pos->next; pos != (head); \
							    pos = n, n = pos->next)

#endif /* defined _NTFS_LIST_H */
