(*
type 'a my_list = Item of ('a * 'a my_list) | Empty
val len : 'a my_list -> int = <fun>
val length : 'a my_list -> int = <fun>
val hd : 'a my_list -> 'a = <fun>
val tl : 'a my_list -> 'a my_list = <fun>
val nth : 'a my_list -> int -> 'a = <fun>
val rev : 'a my_list -> 'a my_list = <fun>
val append : 'a my_list -> 'a my_list -> 'a my_list = <fun>
val rev_append : 'a my_list -> 'a my_list -> 'a my_list = <fun>
val concat : 'a my_list my_list -> 'a my_list = <fun>
val flatten : 'a my_list my_list -> 'a my_list = <fun>
val eq_len : 'a my_list -> 'b my_list -> bool = <fun>
val iter : ('a -> 'b) -> 'a my_list -> unit = <fun>
val map : ('a -> 'b) -> 'a my_list -> 'b my_list = <fun>
val rev_map : ('a -> 'b) -> 'a my_list -> 'c my_list = <fun>
val fold_left : ('a -> 'b -> 'a) -> 'a -> 'b my_list -> 'a = <fun>
val fold_right : ('a -> 'b -> 'b) -> 'a my_list -> 'b -> 'b = <fun>
val iter2 : ('a -> 'b -> 'c) -> 'a my_list -> 'b
my_list -> unit = <fun> val map2 : ('a -> 'b -> 'c) -> 'a my_list -> 'b my_list -> 'c my_list = <fun>
val rev_map2 : ('a -> 'b -> 'c) -> 'a my_list -> 'b my_list -> 'c my_list = <fun>
val fold_left2 : ('a -> 'b -> 'c -> 'a) -> 'a -> 'b my_list -> 'c my_list -> 'a = <fun>
val fold_right2 : ('a -> 'b -> 'c -> 'c) -> 'a my_list -> 'b my_list -> 'c -> 'c = <fun>
val for_all : ('a -> bool) -> 'a my_list -> bool = <fun>
val exists : ('a -> bool) -> 'a my_list -> bool = <fun>
val for_all2 : ('a -> 'b -> bool) -> 'a my_list -> 'b my_list -> bool = <fun>
val exists2 : ('a -> 'b -> bool) -> 'a my_list -> 'b my_list -> bool = <fun>
val mem : 'a -> 'a my_list -> bool = <fun>
val memq : 'a -> 'a my_list -> bool = <fun>
val find : ('a -> bool) -> 'a my_list -> 'a = <fun>
val filter : ('a -> bool) -> 'a my_list -> 'a my_list = <fun>
val find_all : ('a -> bool) -> 'a my_list -> 'a my_list = <fun>
val partition : ('a -> bool) -> 'a my_list -> 'a my_list * 'a my_list = <fun>
val assoc : 'a -> ('a * 'b) my_list -> 'b = <fun>
val assq : 'a -> ('a * 'b) my_list -> 'b = <fun>
val mem_assoc : 'a -> ('a * 'b) my_list -> bool = <fun>
val mem_assq : 'a -> ('a * 'b) my_list -> bool = <fun>
val remove_assoc : 'a -> ('a * 'b) my_list -> ('a * 'b) my_list = <fun>
val remove_assq : 'a -> ('a * 'b) my_list -> ('a * 'b) my_list = <fun>
val remove_all_assoc : 'a -> ('a * 'b) my_list -> ('a * 'b) my_list = <fun>
val remove_all_assq : 'a -> ('a * 'b) my_list -> ('a * 'b) my_list = <fun>
val split : ('a * 'b) my_list -> 'a my_list * 'b my_list = <fun>
val combine : 'a my_list -> 'b my_list -> ('a * 'b) my_list = <fun>
*)


type 'a my_list = 
  | Item of ('a * 'a my_list)
  | Empty
;;

(*  Basic functions *)

let rec len = function
  | Empty	-> 0
  | Item(_, b)  -> 1 + len b
;;

let length = len;;

let hd = function
  | Empty		-> failwith "hd"
  | Item(ret, _)	-> ret
;;

let tl = function
  | Empty	        -> failwith "tl"
  | Item(_, ret)	-> ret
;;

let nth list idx =
  if idx < 0 then invalid_arg "my_list.nth" else
  let rec __nth l i = match l with
    | Empty		-> failwith "nth"
    | Item(head,next)	-> if i == 0
                         then head
                         else __nth next (i-1)
  in __nth list idx
;;

let rev list =
  let rec __rev l ret = match l with
    | Empty		-> ret
    | Item(head, next)	-> __rev next (Item(head, ret))
  in __rev list Empty
;;

let rec append list1 list2 = match list1 with
  | Empty		-> list2
  | Item(a, b)		-> Item(a, (append b list2))
;;

let rev_append list1 list2 = 
  append (rev list1) list2
;;

let rec concat = function
  | Empty	-> Empty
  | Item(a, b)	-> append a (concat b)
;;

let flatten = concat;;

let rec eq_len list1 list2 = match (list1, list2) with
  | (Empty, Empty)		-> true
  | (Empty, _) | (_, Empty)	-> false
  | (Item(_, a), Item(_, b))	-> eq_len a b
;;

(*************************** ITERATORS *************************)

let rec iter f = function
  | Empty		-> ()
  | Item(a, b)		-> begin
                            f a;
                            iter f b
                           end
;;

let rec map f = function
  | Empty		-> Empty
  | Item(a, b)		-> let ok = f a in Item(ok, map f b)
;;

let rev_map f list =
  let rec __rev_map l1 l2 = match l1 with
    | Empty		-> Empty
    | Item(a, b)	-> __rev_map b (Item(f a, l2))
  in __rev_map list Empty
;;

let rec fold_left f x = function
  | Empty		-> x
  | Item(a, b)		-> fold_left f (f x a) b
;;

let rec fold_right f list x = match list with
  | Empty		-> x
  | Item(a, b)		-> f a (fold_right f b x)
;;

(********************* ITERATORS ON TWO LISTS ********************)

let rec iter2 f list1 list2 = match (list1, list2) with
  | (Empty, Empty)		 -> ()
  | (Item(a1, b1), Item(a2, b2)) -> begin
                                     f a1 a2;
                                   iter2 f b1 b2
                                    end
  | (_, _)			 -> raise (Invalid_argument "iter2")
;;

let rec map2 f list1 list2 = match (list1, list2) with
  | (Empty, Empty)		 -> Empty
  | (Item(a1, b1), Item(a2, b2)) -> Item(f a1 a2, map2 f b1 b2)
  | (_, _)			 -> raise (Invalid_argument "iter2")
;;

let rev_map2 f l1 l2 =
  let rec __rev_map2 ret list1 list2 = match (list1, list2) with
    | (Empty, Empty)		   -> ret
    | (Item(a1, b1), Item(a2, b2)) -> __rev_map2 (Item(f a1 a2, ret)) b1 b2
    | (_, _)			   -> raise (Invalid_argument "rev_map2")
  in __rev_map2 Empty l1 l2
;;

let rec fold_left2 f a list1 list2 = match (list1, list2) with
  | (Empty, Empty)			-> a
  | (Item(a1, b1), Item(a2, b2))	-> fold_left2 f (f a a1 a2) b1 b2
  | (_, _)				-> raise (Invalid_argument "fold_left2")
;;

let rec fold_right2 f list1 list2 a = match (list1, list2) with
  | (Empty, Empty)			-> a
  | (Item(a1, b1), Item(a2, b2))	-> f a1 a2 (fold_right2 f b1 b2 a)
  | (_, _)				-> raise (Invalid_argument "fold_right2")
;;

(************************* List scanning *************************)

let rec for_all f = function
  | Empty	-> true
  | Item(a, b)	-> (f a) && for_all f b
;;

let rec exists f = function
  | Empty	-> false
  | Item(a, b)	-> (f a) || exists f b
;;

let rec for_all2 f list1 list2 = match (list1, list2) with
  | (Empty, Empty)		-> true
  | (Item(a1, b1), Item(a2, b2))-> f a1 a2 && for_all2 f b1 b2
  | (_, _)			-> raise (Invalid_argument "for_all2")
;;

let rec exists2 f list1 list2 = match (list1, list2) with
  | (Empty, Empty)		-> false
  | (Item(a1, b1), Item(a2, b2))-> f a1 a2 || exists2 f b1 b2
  | (_, _)			-> raise (Invalid_argument "exists2")
;;

let rec mem need = function
  | Empty	-> false
  | Item(a, b)	-> a = need || mem need b
;;

let rec memq need = function
  | Empty	-> false
  | Item(a, b)  -> a == need || memq need b
;;

(************************* List seaching *************************)

let rec find f = function
  | Empty	-> raise Not_found
  | Item(a, b)	-> if f a then a else find f b
;;

let filter f list =
  let rec __filter l ret = match l with
    | Empty	-> rev ret
    | Item(a, b)-> if f a
		   then __filter b (Item(a, ret))
                   else __filter b ret
  in __filter list Empty
;;

let find_all = filter;;

let partition f list =
  let rec __part l good bad = match l with
    | Empty	-> (rev good, rev bad)
    | Item(a, b)-> if f a
		   then __part b (Item(a, good)) bad
                   else __part b good (Item(a, bad))
  in __part list Empty Empty
;;

(************************* Association lists *************************)

let rec assoc need = function
  | Empty		-> raise Not_found
  | Item((a, b), next)	-> if need = a then b else assoc need next
;;

let rec assq need = function
  | Empty		-> raise Not_found
  | Item((a, b), next)	-> if need == a then b else assq need next
;;

let rec mem_assoc need = function
  | Empty		-> false
  | Item((a, _), next)	-> if need = a then true else mem_assoc need next
;;

let rec mem_assq need = function
  | Empty		-> false
  | Item((a, _), next)	-> if need == a then true else mem_assq need next
;;

let rec remove_assoc key = function
  | Empty		-> Empty
  | Item((a, b), c)	-> if key = a then c else Item((a, b), (remove_assoc key c))
;;

let rec remove_assq key = function
  | Empty		-> Empty
  | Item((a, b), c)	-> if key == a then c else Item((a, b), (remove_assq key c))
;;


let rec remove_all_assoc a = function
  | Empty		-> Empty
  | Item((b, c), d)	-> if a = b then remove_all_assoc a d else Item((b, c), remove_all_assoc a d)
;;

let rec remove_all_assq a = function
  | Empty		-> Empty
  | Item((b, c), d)	-> if a == b then remove_all_assoc a d else Item((b, c), remove_all_assoc a d)
;;

(************************* Lists of pairs  *************************)

let split list =
  let rec __split t left right = match t with
    | Empty		-> (rev left, rev right)
    | Item((a,b), next)	-> __split next (Item(a, left)) (Item(b, right))
  in __split list Empty Empty
;;

let rec combine list1 list2 = match (list1, list2) with
  | (Empty, Empty)		-> Empty
  | (Item(a1, b1), Item(a2, b2))-> Item((a1, a2), combine b1 b2)
  | (_, _)			-> raise (Invalid_argument "combine")
;;
