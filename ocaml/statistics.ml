(* Pure functional implementation – no mutable state *)

let data = [10; 20; 20; 34; 43; 25; 56]

(* ---------- mean ---------- *)
let mean lst =
  let sum = List.fold_left (+) 0 lst in
  float_of_int sum /. float_of_int (List.length lst)

(* ---------- median ---------- *)
let median lst =
  let sorted = List.sort compare lst in
  let n = List.length sorted in
  if n mod 2 = 1 then
    float_of_int (List.nth sorted (n / 2))
  else
    let a = List.nth sorted (n / 2 - 1)
    and b = List.nth sorted (n / 2) in
    float_of_int (a + b) /. 2.0

(* ---------- mode (highest frequency; on ties the smallest value) ---------- *)
let mode lst =
  let sorted = List.sort compare lst in
  (* fold that keeps (current_value, current_count, best_value, best_count) *)
  let rec aux remaining cur_val cur_cnt best_val best_cnt =
    match remaining with
    | [] -> best_val
    | x :: xs ->
        if x = cur_val then
          let new_cnt = cur_cnt + 1 in
          if new_cnt > best_cnt then
            aux xs cur_val new_cnt x new_cnt
          else
            aux xs cur_val new_cnt best_val best_cnt
        else
          aux xs x 1 best_val best_cnt
  in
  match sorted with
  | [] -> failwith "empty list"
  | h :: t -> aux t h 1 h 1

(* ---------- driver ---------- *)
let () =
  Printf.printf "Data: ";
  List.iter (fun x -> Printf.printf "%d " x) data;
  print_newline ();
  Printf.printf "Mean   : %.2f\n" (mean data);
  Printf.printf "Median : %.2f\n" (median data);
  Printf.printf "Mode   : %d\n"   (mode data)
