#include <stdio.h>
#include "boolean.h"
#include "set.h"

void CreateEmpty(Set *S){
    S->Count = Nil;
}

boolean IsEmpty(Set S){
    return (S.Count == 0); 
}

boolean IsFull(Set S){
    return (S.Count == MaxEl);
}

void Insert(Set *S, infotype Elmt){
    if (!IsMember(*S, Elmt)){
        S->Elements[S->Count] = Elmt;
        S->Count++;
    }
}

void Delete(Set *S, infotype Elmt){
    if (IsMember(*S, Elmt)){
        int i = 0;
        while (i<S->Count && S->Elements[i] != Elmt){
            i++;
        }
        while (i<S->Count-1){
            S->Elements[i] = S->Elements[i+1];
            i++;
        }
        S->Count--;
    }
}

boolean IsMember(Set S, infotype Elmt){
    int i;
    boolean found = false;
    for (i=0;i<S.Count;i++){
        if (S.Elements[i]==Elmt){
            found = true;
        } 
    }
    return (found);
}