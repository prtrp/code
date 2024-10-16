fn main() {
  let number: i32 = 1;

  if number == 3 {
    println!("number is 3");
  } else if  number == 1 {
    println!("number is 1");
  } else {
    println!("no number is");
  }

  println!("the result is: {}", return_loop());
}

fn return_loop () -> i32 {
  let mut counter :i32  = 0;
  let result = loop {
    counter += 1;

    if counter == 10 {
      break counter * 2;
    }
  };
  result
}
