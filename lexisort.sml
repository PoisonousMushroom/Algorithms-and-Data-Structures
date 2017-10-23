(*Oana Miron Pb3*)
datatype 'a list=cons of 'a*'a list|nil;

datatype 'a Ord=Ord of 'a *'a -> bool;

(*bubblesorting*)
fun bubblesort(nil,ord)=nil
  | bubblesort(cons(x,nil):'a list,ord)=cons(x,nil)
  | bubblesort(cons(a,cons(b,t)):'a list,ord:'a Ord)=let val Ord(func)=ord; in
                  if func(a,b)=false then cons(b,bubblesort(cons(a,t),ord))
                  else cons(a,bubblesort(cons(b,t),ord)) end;

(*checks if function is sorted*)
fun sorted(nil,ord:'a Ord)=true
  | sorted(cons(a,nil):'a list,ord:'a Ord)=true
  | sorted(cons(a,cons(b,t)):'a list,ord:'a Ord)=let val Ord(func)=ord; in
               if func(a,b)=true then sorted(cons(b,t),ord) else false end;

(*check if sorted for bubblesort*)
fun sortbubble(nil,ord)=nil
  | sortbubble(x:'a list,ord)= if sorted(x,ord)=true then x else sortbubble(bubblesort(x,ord),ord);

val Lexicographic: string Ord=Ord(fn(x,y)=> x<=y);

  sortbubble(cons("a",cons("b",nil)),Lexicographic);
  sortbubble(nil,Lexicographic);
  sortbubble(cons("a",nil),Lexicographic);
  sortbubble(cons("b",cons("a",nil)),Lexicographic);
