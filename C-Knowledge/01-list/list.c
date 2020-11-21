#include <stdio.h>
#include <string.h>
#include "list.h"

struct kobject {
    struct list_head list;
    char name[20];
    int len;
};




int main()
{
    struct kobject obj1,obj2,obj3,obj4;
    struct kobject *tmp;
    struct list_head *pos;

    static struct list_head name_len__pool;
    INIT_LIST_HEAD(&name_len__pool);

    // Ini
    memcpy(obj1.name,"tom",sizeof("tom"));
    obj1.len = 1;

    memcpy(obj2.name,"cat",sizeof("cat"));
    obj2.len = 2;

    memcpy(obj3.name,"jerry",sizeof("jerry"));
    obj3.len = 3;

    memcpy(obj4.name,"xiaoming",sizeof("xiaoming"));
    obj4.len = 4;



    //把1，2，3插入name_len_pool链表
    list_add_tail(&obj1.list, &name_len__pool);
    list_add_tail(&obj2.list, &name_len__pool);
    list_add_tail(&obj3.list, &name_len__pool);

    //打印name_len_pool链表
    list_for_each(pos, &name_len__pool)
    {
       tmp = list_entry(pos, struct kobject, list);
        printf("name=%s length=%d\n",tmp->name,tmp->len);
    }

    //把节点4插入节点2前
    
    list_add_tail(&obj4.list, &obj2.list);
    printf("After list_add_tail(obj4,obj2):\n");
    list_for_each(pos, &name_len__pool)
    {
       tmp = list_entry(pos, struct kobject, list);
        printf("name=%s length=%d\n",tmp->name,tmp->len);
    }


}
