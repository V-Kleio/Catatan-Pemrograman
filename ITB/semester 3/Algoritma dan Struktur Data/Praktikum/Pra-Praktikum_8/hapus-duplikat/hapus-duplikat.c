#include "hapus-duplikat.h"
#include "listlinier.h"

#include <stdlib.h>

List hapusDuplikat(List l) 
{
	List l2, deleted;
	CreateList(&l2);
	CreateList(&deleted);

	Address p = FIRST(l);

	while (p != NULL) 
    {
		ElType e = INFO(p);
		p = NEXT(p);
		if (indexOf(deleted, e) != IDX_UNDEF) 
        {
            continue;
        }
		if (l2 == NULL) 
        {
			insertFirst(&l2, e);
		} 
        else 
        {
			int id = indexOf(l2, e);
			if (id == IDX_UNDEF) 
            {
				Address n = l2;
				int ctr = 0;
				while (n != NULL) 
                {
					if (INFO(n) > e) 
                    {
						insertAt(&l2, e, ctr);
						break;
					}
					n = NEXT(n);
					ctr++;
				}
			}
            else 
            {
				ElType dump;
				deleteAt(&l2, id, &dump);
				insertLast(&deleted, dump);
			}
		}
	}
	return l2;
}