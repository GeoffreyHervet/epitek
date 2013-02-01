(*
  1. val length : 'a list -> int = <fun>
  2. val hd : 'a list -> 'a = <fun>
  3. val tl : 'a list -> 'a list = <fun>
  4. val nth : exn list -> int -> exn = <fun>
  5. val rev : 'a list -> 'a list = <fun>
  6. val append : 'a list -> 'a list -> 'a list = <fun>
  7. val rev_append : 'a list -> 'a list -> 'a list = <fun>
  8. val flatten : 'a list list -> 'a list = <fun>
  9. val iter : ('a -> 'b) -> 'a list -> unit = <fun>
 10. val map : ('a -> 'b) -> 'a list -> 'b list = <fun>
 11. val fold_left : ('a -> 'b -> 'a) -> 'a -> 'b list -> 'a = <fun>
 12. val for_all : ('a -> bool) -> 'a list -> bool = <fun>
 13. val exists : ('a -> bool) -> 'a list -> bool = <fun>
 14. val mem : 'a -> 'a list -> bool = <fun>
 15. val memq : 'a -> 'a list -> bool = <fun>
 16. val filter : ('a list -> bool) -> 'a list -> 'a list = <fun>
 17. val mem_assoc : 'a -> ('a * bool) list -> bool = <fun>
 18. val assoc : 'a -> ('a * 'b) list -> 'b = <fun>
 19. val split : ('a * 'b) list -> 'a list * 'b list = <fun>
 20. val remove_assoc : 'a -> ('a * 'b) list -> ('a * 'b) list = <fun>

B01. val concat : 'a list list -> 'a list = <fun>
B02. val rev_map : ('a -> 'b) -> 'a list -> 'b list = <fun>
B03. val fold_right : ('a -> 'b -> 'b) -> 'a list -> 'b -> 'b = <fun>
B04. val iter2 : ('a -> 'b -> 'c) -> 'a list -> 'b list -> 'd list = <fun>
B05. val map2 : ('a -> 'b -> 'c) -> 'a list -> 'b list -> 'c list = <fun>
B06. val rev_map2 : ('a -> 'b -> 'c) -> 'a list -> 'b list -> 'c list = <fun>
B07. val fold_left2 : ('a -> 'b -> 'c -> 'a) -> 'a -> 'b list -> 'c list -> 'a = <fun>
B08. val fold_right2 : ('a -> 'b -> 'c -> 'c) -> 'a list -> 'b list -> 'c -> 'c = <fun>
B09. val for_all2 : ('a -> 'b -> bool) -> 'a list -> 'b list -> bool = <fun>
B11. val exists2 : ('a -> 'b -> bool) -> 'a list -> 'b list -> bool = <fun>
B12. val find : ('a -> bool) -> 'a list -> 'a = <fun>
B13. val find_all : ('a list -> bool) -> 'a list -> 'a list = <fun>
B14. val partition : ('a -> bool) -> 'a list -> 'a list * 'a list = <fun>
B15. val assq : 'a -> ('a * 'b) list -> 'b = <fun>
B16. val mem_assq : 'a -> ('a * bool) list -> bool = <fun>
B17. val remove_assq : 'a -> ('a * 'b) list -> ('a * 'b) list = <fun>
B18. val combine : 'a list -> 'b list -> ('a * 'b) list = <fun>
*)

let rec length _list = match _list with
  | [] 		-> 0
  | _::_next	-> 1 + length _next
;;

let hd _list = match _list with
  | []		-> failwith "hd"
  | _item::_	-> _item
;;

let tl _list = match _list with
  | []		-> failwith "tl"
  | a::ret	-> ret
;;

let rec nth _list _pos =
  if _pos < 0
  then
    Invalid_argument "my_list.nth"
  else
    match _list with
      | []		-> failwith "nth"
      | _item::_next	-> if _pos == 0
			   then _item
                           else nth _next (_pos - 1)
;;

(*
 * item1::item2::[]
 *)

let rev _list =
  let rec __rev _l1 _l2 =
    match _l1 with
      | []		-> _l2
      | _item::_next	-> __rev _next (_item::_l2)
  in __rev _list []
;;

let rec append _list1 _list2 = match _list1 with
  | _head::_next	-> _head::(append _next _list2)
  | []			-> match _list2 with
    | []		-> []
    | _head::_next	-> _head::(append [] _next)
;;

let rev_append l1 l2 =
  let rec _a l ret = match l with
  | [] -> ret
  | a::b -> _a b (a::ret)     
  in _a l2 (_a l1 [])
;;

let rec concat _list = match _list with
  | []			-> []
  | _head::_next	-> append _head (concat _list)
;;

let flatten = concat;;


(*************************** ITERATORS *************************)

let rec iter f _list = match _list with
  | []			-> ()
  | _head::_next	-> begin
			    f(_head);
                            iter f _next
                           end
;;

let rec map f _list = match _list with
  | []			-> []
  | _head::_next	-> f(_head)::map f _next
;;

let rec rev_map _f _list =
  let rec __rev_map f l1 l2 = match l1 with
    | []		-> l2
    | _head::_next	-> __rev_map f _next (f(_head)::l2)
  in __rev_map _f _list []
;;


let rec fold_left f a _list = match _list with
  | []			-> a
  | _head::_next	-> fold_left f (f a _head) _next
;;

let rec fold_right f _list b = match _list with
  | []			-> b
  | _head::_next	-> f _head (fold_right f _next b)
;;

(********************* ITERATORS ON TWO LISTS ********************)

let rec iter2 f _list1 _list2 = 
  if length _list2 != length _list1
  then raise (Invalid_argument "iter2 : invalid size")
  else
    match (_list1, _list2) with
    | (_, []) | ([], _)			-> []
    | (_head1::_next1, _head2::_next2)	-> begin
					     f _head1 _head2;
                                             iter2 f _next1 _next2
                                            end
;;

let rec map2 f _list1 _list2 = 
  if length _list2 != length _list1
  then raise (Invalid_argument "map2 : different sizes")
  else
    match (_list1, _list2) with
    | (_head1::_next1, _head2::_next2)	-> (f _head1 _head2) :: (map2 f _next1 _next2)
    | (_, []) | ([], _)			-> []
;;

let rev_map2 f _l1 _l2 = 
  if length _l2 != length _l1
  then raise (Invalid_argument "rev_map2 : different sizes")
  else let rec __rev_map2 f _list1 _list2 ret = match (_list1, _list2) with
    | (_, []) | ([], _)			-> ret
    | (_head1::_next1, _head2::_next2)	-> __rev_map2 f _next1 _next2 ((f _head1 _head2)::ret)
  in __rev_map2 f _l1 _l2 []
;;

let fold_left2 f _a _l1 _l2 = 
  if length _l2 != length _l1
  then raise (Invalid_argument "fold_left2 : different sizes")
  else let rec __fold_left2 f a _list1 _list2 = match (_list1, _list2) with
    | (_, []) | ([], _)			-> a
    | (_head1::_next1, _head2::_next2)	-> __fold_left2 f (f a _head1 _head2) _next1 _next2
  in __fold_left2 f _a _l1 _l2
;;

let fold_right2 f _l1 _l2 _a  = 
  if length _l2 != length _l1
  then raise (Invalid_argument "fold_right2 : different sizes")
  else let rec __fold_right2 f _list1 _list2 a = match (_list1, _list2) with
    | (_, []) | ([], _)			-> a
    | (_head1::_next1, _head2::_next2)	-> f _head1 _head2 (__fold_right2 f _next1 _next2 a)
  in __fold_right2 f _l1 _l2 _a
;;

(************************* List scanning *************************)

let rec for_all predicate _list = match _list with
  | []			-> true
  | _head::_next	-> (predicate _head) && for_all predicate _next
;;

let rec exists predicate _list = match _list with
  | []			-> false
  | _head::_next	-> (predicate _head) || exists predicate _next
;;

let rec for_all2 predicate _l1 _l2 =
  if length _l1 != length _l2
  then raise (Invalid_argument "for_all2 : different sizes")
  else let rec __for_all2 f _list1 _list2 = match (_list1, _list2) with
    | (_, []) | ([], _)			-> true
    | (_head1::_next1, _head2::_next2)	-> (predicate _head1 _head2) && __for_all2 f _next1 _next2
  in __for_all2 predicate _l1 _l2
;;

let rec exists2 predicate _l1 _l2 =
  if length _l1 != length _l2
  then raise (Invalid_argument "exists2 : different sizes")
  else let rec __exists2 f _list1 _list2 = match (_list1, _list2) with
    | (_, []) | ([], _)			-> false
    | (_head1::_next1, _head2::_next2)	-> (predicate _head1 _head2) || __exists2 f _next1 _next2
  in __exists2 predicate _l1 _l2
;;

let rec mem _need _list = match _list with
  | []			-> false
  | _head::_next	-> if 0 == compare _need _head then true else mem _need _next
;;

let rec memq _need _list = match _list with
  | []			-> false
  | _head::_next	-> if _need == _head then true else mem _need _next
;;

(************************* List seaching *************************)

let rec find _predicate _list = match _list with
  | []			-> raise Not_found
  | _head::_next	-> if true == _predicate _head then _head else find _predicate _next
;;

let rec filter _predicate _list =
  let rec __filter f _l ret = match _l with
    | []		-> ret
    | _head::_next	-> if true == f _l
                           then __filter f _next (_head::ret)
                           else __filter f _next ret
  in __filter _predicate _list []
;;

let find_all = filter;;

let partition _predicate _list =
  let rec __partition _f _l _predOk _predFail = match _l with
    | []		-> (rev _predOk, rev _predFail)
    | _head::_next	-> if _f _head
                           then __partition _f _next (_head::_predOk) _predFail
                           else __partition _f _next _predOk (_head::_predFail)
  in __partition _predicate _list [] []
;;

(************************* Association lists *************************)

let rec assoc _need _list = match _list with
  | []			-> raise Not_found
  | (a,b)::next		-> if 0 == compare _need a then b else assoc _need next
;;

let rec assq _need _list = match _list with
  | []			-> raise Not_found
  | (a,b)::next		-> if _need == a then b else assoc _need next
;;

let rec mem_assoc _need _list = match _list with
  | []			-> false
  | (a,b)::next		-> if 0 == compare _need a then true else assoc _need next
;;

let rec mem_assq _need _list = match _list with
  | []			-> false
  | (a,b)::next		-> if _need == a then true else assoc _need next
;;

let remove_assoc _seek _list =
  let rec __remove_assoc  _s _l ret = match _l with
    | []		-> rev ret
    | (a,b)::next	-> if 0 == compare a _s
			   then __remove_assoc _s next ((a,b)::ret)
                           else __remove_assoc _s next ret
  in __remove_assoc _seek _list []
;;

let remove_assq _seek _list =
  let rec __remove_assq  _s _l ret = match _l with
    | []		-> rev ret
    | (a,b)::next	-> if a == _s
			   then __remove_assq _s next ((a,b)::ret)
                           else __remove_assq _s next ret
  in __remove_assq _seek _list []
;;

(************************* Lists of pairs  *************************)

let split _list =
  let rec __split _l left right = match _l with
    | []		-> (rev left, rev right)
    | (a,b)::next	-> __split next (a::left) (b::right)
  in __split _list [] []
;;

let combine _l1 _l2 = 
  if length _l1 != length _l2
  then raise (Invalid_argument "combine")
  else let rec __combine left right ret = match (left, right) with
    | ([], _) | (_, [])			-> rev ret
    | (_head1::_next1, _head2::_next2)	-> __combine _next1 _next2 ((_head1,_head2)::ret)
  in __combine _l1 _l2 []
;;


(*  List.rev_map2 f l1 l2 gives the same result as List.rev (List.map2 f l1 l2),
 *  but is tail-recursive and more efficient.
 *)

(*
let rec rev_map _f _list =
  let __rev_map f l1 l2 = match l1 with
    | []		-> l2
    | _head::_next	-> __rev_map f _next (f(head)::l2)
  in __rev_map _f _list []
;;
*)
