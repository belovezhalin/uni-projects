//Anhelina Belavezha 
#include <iostream>
using namespace std;

/*struct NODE_STRUCT {
OBJECT_TYPE* object;
BYTE use;
NODE_STRUCT* next;}*/
/////////////////////////////////////////////////////////////////////////////////////////
NODE_STRUCT* NewNode() {
NODE_STRUCT *wezel = new NODE_STRUCT();
wezel -> object = new OBJECT_TYPE[SIZE];
return wezel;}
/////////////////////////////////////////////////////////////////////////////////////////
void DeleteNode(NODE_STRUCT* wezel) {
delete [] wezel -> object;
delete wezel;}
/////////////////////////////////////////////////////////////////////////////////////////
void Clear(NODE_STRUCT** wezel) {
NODE_STRUCT* b = *wezel;
NODE_STRUCT* a = NULL;
while (b != NULL) {
	a = b;
	DeleteNode(a);
	b = b -> next;}
*wezel = NULL;}
/////////////////////////////////////////////////////////////////////////////////////////
void AddFirst(NODE_STRUCT** array, OBJECT_TYPE* wezel) {

if (*array == NULL) *array = NewNode(); 
	
NODE_STRUCT* b = *array;
if (b -> use < SIZE) {
   for (int i = b -> use; i > 0; *(b -> object + i) = *(b -> object + i - 1), i--);
   b -> use++;
   *(b -> object) = *wezel;} 
else {
	NODE_STRUCT* c = NewNode();
	NODE_STRUCT* d = b;
	c -> use++;
	*(c -> object) = *wezel;
	c -> next = d;
	*array = c;}
}
/////////////////////////////////////////////////////////////////////////////////////////
void AddLast(NODE_STRUCT** array, OBJECT_TYPE* wezel) {

if (*array == NULL) *array = NewNode(); 

NODE_STRUCT* b = *array;
while (b -> next != NULL) b = b -> next;
if (b -> use < SIZE) {
	*(b -> object + b -> use) = *wezel;
	b -> use++;}
else {
    NODE_STRUCT* o = NewNode();
    *(o -> object + o -> use) = *wezel;
    o -> use++;
    b -> next = o;}
}	
/////////////////////////////////////////////////////////////////////////////////////////
void GetFirst(NODE_STRUCT* array, NODE_STRUCT** q, BYTE* i) {
	
if (array == NULL) {*q = NULL; return;}

*q = array; 
*i = 0;
}
/////////////////////////////////////////////////////////////////////////////////////////
void GetPrev(NODE_STRUCT* array, NODE_STRUCT* wsk, BYTE bi, NODE_STRUCT** q, BYTE* i) {
if (bi == 0) {
	if (array == wsk) *q = NULL;
	else {
		while (array -> next != wsk) array = array -> next;
		*q = array;
		*i = array -> use - 1;}
	return;}
*q = wsk;
*i = bi - 1;
}
/////////////////////////////////////////////////////////////////////////////////////////
void GetNext(NODE_STRUCT* array, NODE_STRUCT* wsk, BYTE j, NODE_STRUCT** q, BYTE* i) {
if (j + 1 == wsk -> use) {
	if (wsk -> next != NULL) {
		*q = wsk -> next;
		*i = 0;}
	else *q = NULL;}
else {
	*q = wsk;
	*i = j + 1;}
}
/////////////////////////////////////////////////////////////////////////////////////////
void GetLast(NODE_STRUCT* array, NODE_STRUCT** q, BYTE* i) {
	
if (array == NULL) {*q = NULL; return;}

while (array -> next != NULL) array = array -> next;
*q = array;
*i = (*q) -> use - 1;
}
/////////////////////////////////////////////////////////////////////////////////////////
void Function(NODE_STRUCT* array, NODE_STRUCT* wsk, BYTE bi, OBJECT_TYPE* wezel) {
NODE_STRUCT** q = &array;
if ((*q) != wsk) {
    while ((*q) -> next != wsk) {
        if ((*q) -> next == NULL) return;
        (*q) = (*q) -> next;}}
        
if (wsk -> use < SIZE) {
    wsk -> use++;
    for (int i = wsk -> use - 1; bi + 1 < i; *(wsk -> object + i) = *(wsk -> object + i - 1), i--);
    *(wsk -> object + bi + 1) = *wezel;}
else {
    if (wsk -> next == NULL) {
        NODE_STRUCT* a = NewNode();
        a -> use++;
        *(a -> object) = *(wsk -> object + SIZE - 1);
        wsk -> next = a;
        for (int i = wsk -> use - 1; bi + 1 < i; *(wsk -> object + i) = *(wsk -> object + i - 1), i--);
        
        if (bi + 1 < SIZE) *(wsk -> object + bi + 1) = *wezel;
        else *(( wsk -> next) -> object) = *wezel;}
        
    else {
        NODE_STRUCT* a = NewNode();
        a -> use++; 
        *(a -> object) = *(wsk -> object + SIZE - 1);
        a -> next = wsk -> next;
        wsk -> next = a;
        for (int i = wsk -> use - 1; bi + 1 < i; *(wsk -> object + i) = *(wsk -> object + i - 1), i--);
        
        if (bi + 1 < SIZE) *(wsk -> object + bi + 1) = *wezel;
        else *((wsk -> next) -> object) = *wezel;}}
}

void InsertPrev(NODE_STRUCT** array, NODE_STRUCT* wsk, BYTE bi, OBJECT_TYPE* wezel) {
NODE_STRUCT** q = array;
NODE_STRUCT* b = *array;
if (wsk -> use == SIZE) {
    if ((*q) != wsk) {
        while ((*q) -> next != wsk) {
            if ((*q) -> next == NULL) {*array = b; return;}
            (*q) = (*q) -> next;}
            
        if (bi != 0) {
            Function(*array, *q, (*q) -> use - 1, &(*(wsk -> object)));
            for (int i = 0; bi - 1 > i; *(wsk -> object + i) = *(wsk -> object + i + 1), i++);
            *(wsk -> object + bi - 1) = *wezel;}
        else Function(*array, *q, (*q) -> use - 1, wezel);
        *array = b;}
        
    else {
        NODE_STRUCT* a = NewNode();
        a -> next = wsk;
        a -> use = 1;
        
        if (bi != 0) {
            *(a -> object) = *(wsk -> object);
            for (int i = 0; bi - 1 > i; *(wsk -> object + i) = *(wsk -> object + i + 1), i++);
            *(wsk -> object + bi - 1) = *wezel;}
        else *(a -> object) = *wezel;
        *array = a;}}
else {
    if ((*q) != wsk) {
        while ((*q) -> next != wsk) {
            if ((*q) -> next == NULL) {*array = b; return;}
            (*q) = (*q) -> next;}}
    wsk -> use++;
    for (int i = wsk -> use - 1; bi < i; *(wsk -> object + i) = *(wsk-> object + i - 1), i--);
    *(wsk -> object + bi) = *wezel;
    *array = b;}
}
/////////////////////////////////////////////////////////////////////////////////////////
void InsertNext(NODE_STRUCT* array, NODE_STRUCT* wsk, BYTE bi, OBJECT_TYPE* wezel) {
NODE_STRUCT** q = &array;
    if ((*q) != wsk) {
        while ((*q) -> next != wsk) {
            if ((*q) -> next == NULL) return;
            (*q) = (*q) -> next;}}
            
    if (wsk -> use < SIZE) {
        wsk -> use++;
        for (int i = wsk -> use - 1; bi + 1 < i; *(wsk -> object + i) = *(wsk -> object + i - 1), i--);
        *(wsk -> object + bi + 1) = *wezel;}
        
    else {
        if (wsk -> next == NULL) {
            NODE_STRUCT* a = NewNode();
            a -> use++;
            *(a -> object) = *(wsk -> object + SIZE - 1);
            wsk -> next = a;
            for (int i = wsk -> use - 1; bi + 1 < i; *(wsk -> object + i) = *(wsk -> object + i - 1), i--);
                
            if (bi + 1 < SIZE) *(wsk -> object + bi + 1) = *wezel;
            else *((wsk -> next) -> object) = *wezel;}
                
        else if (wsk -> next -> use == SIZE) {
            NODE_STRUCT* a = NewNode();
            a -> use++;
            *(a -> object) = *(wsk -> object + SIZE - 1);
            a -> next = wsk -> next;
            wsk -> next = a;
            for (int i = wsk -> use - 1; bi + 1 < i; *(wsk -> object + i) = *(wsk -> object + i - 1), i--);
            
            if (bi + 1 < SIZE) *(wsk -> object + bi + 1) = *wezel;
            else *((wsk -> next) -> object) = *wezel;}
                
        else {
            wsk -> next -> use++;
            
            for (int i = wsk -> next -> use - 1; i > 0; *((wsk -> next) -> object + i) = *((wsk -> next) -> object + i - 1), i--);
            *((wsk -> next) -> object) = *(wsk -> object + SIZE - 1);
            for (int i = wsk -> use - 1; bi + 1 < i; *(wsk -> object + i) = *(wsk -> object + i - 1), i--);
            
            if (bi + 1 < SIZE) *(wsk -> object + bi + 1) = *wezel;
            else *((wsk -> next) -> object) = *wezel;}
    }
}
/////////////////////////////////////////////////////////////////////////////////////////
void RemoveFirst(NODE_STRUCT** array) {
	
if (*array == NULL) return;

(*array) -> use--;
if((*array) -> use == 0) {
	NODE_STRUCT* a = *array;
	(*array) = (*array) -> next;
	DeleteNode(a);
	return;}
else for (int i = 0; i < (*array) -> use; *((*array) -> object + i) = *((*array) -> object + i + 1), i++);
}
/////////////////////////////////////////////////////////////////////////////////////////
void RemovePrev(NODE_STRUCT** array, NODE_STRUCT* wsk, BYTE i) {
if (i > 0) { 

   if (*array == NULL) return;

   wsk -> use--;
   if (wsk -> use == 0) {
	  if (*array == wsk) {
		  NODE_STRUCT* b = *array;
		  b = b -> next;
		  DeleteNode(*array);
		  *array = b;
		  return;}
		
	    NODE_STRUCT* b = *array;
	    while (b -> next != wsk) b = b -> next;
	    b -> next = wsk -> next;
	    DeleteNode(wsk);}
   else for (int j = i - 1; j < wsk -> use; *(wsk -> object + j) = *(wsk -> object + j + 1), j++);}
else {
	if (*array == wsk) return;
	NODE_STRUCT* b = *array;
	while (b -> next != wsk) b = b -> next;
	i = b -> use - 1;
	
	if (*array == NULL) return;

    b -> use--;
    if (b -> use == 0) {
	    if (*array == b) {
		   NODE_STRUCT* q = *array;
		   q = q -> next;
		   DeleteNode(*array);
		   *array = q;
		   return;}
		
	    NODE_STRUCT* q = *array;
	    while (q -> next != b) q = q -> next;
	    q -> next = b -> next;
	    DeleteNode(b);}
    else for (int j = i; j < b -> use; *(b -> object + j) = *(b -> object + j + 1), j++);
}	
} 
/////////////////////////////////////////////////////////////////////////////////////////
void RemoveCurrent(NODE_STRUCT** array, NODE_STRUCT* wezel, BYTE i) {
	
if (*array == NULL) return;

wezel -> use--;
if (wezel -> use == 0) {
	if (*array == wezel) {
		NODE_STRUCT* b = *array;
		b = b -> next;
		DeleteNode(*array);
		*array = b;
		return;}
		
	NODE_STRUCT* b = *array;
	while (b -> next != wezel) b = b -> next;
	b -> next = wezel -> next;
	DeleteNode(wezel);}
else for (int j = i; j < wezel -> use; *(wezel -> object + j) = *(wezel -> object + j + 1), j++);
}
/////////////////////////////////////////////////////////////////////////////////////////
void RemoveNext(NODE_STRUCT* array, NODE_STRUCT* wsk, BYTE i) {
NODE_STRUCT** a = &array;
if (i + 1 != wsk -> use) {
	 
	if (*a == NULL) return;

    wsk -> use--;
    if (wsk -> use == 0) {
	   if (*a == wsk) {
		   NODE_STRUCT* b = *a;
		   b = b -> next;
		   DeleteNode(*a);
		   *a = b;
		   return;}
		
	    NODE_STRUCT* b = *a;
	    while (b -> next != wsk) b = b -> next;
	    b -> next = wsk -> next;
	    DeleteNode(wsk);}
    else for (int j = i + 1; j < wsk -> use; *(wsk -> object + j) = *(wsk -> object + j + 1), j++);
} 
else {
	NODE_STRUCT* b = wsk -> next;
	if (b == NULL) return;
	
	i = 0;
	
	if (*a == NULL) return;

    b -> use--;
    if (b -> use == 0) {
	   if (*a == b) {
		   NODE_STRUCT* c = *a;
		   c = c -> next;
		   DeleteNode(*a);
		   *a = c;
		   return;}
		
	    NODE_STRUCT* c = *a;
	    while (c -> next != b) c = c -> next;
	c -> next = b -> next;
	DeleteNode(b);}
else for (int j = i; j < b -> use; *(b -> object + j) = *(b -> object + j + 1), j++);
}	
}
/////////////////////////////////////////////////////////////////////////////////////////
void RemoveLast(NODE_STRUCT** array) {
	
if (*array == NULL) return;
	
NODE_STRUCT* b = *array;
if (b -> next == NULL) {
	b -> use--;
	if (b -> use == 0) {
		DeleteNode(b);
		*array = NULL;}
	return;}
while (b -> next -> next != NULL) b = b -> next;
b -> next -> use--;
if (b -> next -> use == 0) {
	DeleteNode(b -> next);
	b -> next = NULL;}
}
/////////////////////////////////////////////////////////////////////////////////////////
void Find(NODE_STRUCT* array, OBJECT_TYPE* wezel , NODE_STRUCT** wsk, BYTE* i) {
while(array != NULL) {
	for (int j = 0; j < array -> use; j++) {
		if (*(array -> object + j) == *wezel) {
			*i = j; *wsk = array;
			return;}}
	array = array -> next;}
*wsk = NULL;
return;
}
/////////////////////////////////////////////////////////////////////////////////////////
void Compress(NODE_STRUCT* array) {
if (array != NULL) {
NODE_STRUCT* wezel = array;
NODE_STRUCT* c = wezel -> next;
while (c != NULL) {
	if (c -> use == 0) {
	   wezel -> next = c -> next;
	   DeleteNode(c);
	   c = wezel -> next;}
	else if (wezel -> use < SIZE) {
		*(wezel -> object + wezel -> use) = *(c -> object);
		for (int i = 0; i < c -> use - 1; *(c -> object + i) = *(c -> object + i + 1), i++);
		wezel -> use++;
		c -> use--;}
	else {wezel = c; c = wezel -> next;}}
}	
}
/////////////////////////////////////////////////////////////////////////////////////////
void Reverse(NODE_STRUCT* array) {
if (array != NULL) {
NODE_STRUCT* b = array;
while (b != NULL) b = b -> next;
NODE_STRUCT* a = NULL;
NODE_STRUCT** q = &a;
while (array -> next != NULL) {
	BYTE i; NODE_STRUCT* o;
	GetLast(array, &o, &i);
	AddLast(q, o -> object + i);
	RemoveLast(&array);} 
for (int j = array -> use - 1; j >= 0; AddLast(q, array -> object + j), j--);
array -> use = 0;
array -> next = *q;
Compress(array);		
}  
}




 

 
