fn preprocess(st: & [u8], table: &mut Vec<i32>) {
    let mut len = 0;
    table.push(0);

    while table.len() < st.len() {
        if st[table.len()] == st[len] {
            len += 1;
            table.push(len as i32);
        } else if len > 0 {
            len = table[len - 1] as usize;
        } else {
            table.push(0);
        }
    }
}

fn search(patt: & [u8], text: & [u8]) -> Vec<usize> {
    let mut result : Vec<usize> = Vec::new();
    let (mut i, mut j) = (0, 0);

    let mut table: Vec<i32> = Vec::new();
    preprocess(patt, &mut table);

    while i < text.len() {
        if patt[j] == text[i] {
            i += 1;
            j += 1;
        }

        if j == patt.len() {
            result.push(i - j);
            j = table[j - 1] as usize;
        } else if i < text.len() && patt[j] != text[i] {
            if j > 0 {
                j = table[j - 1] as usize;
            } else {
                i += 1;
            }
        }
    }

    result
}

fn main() {
    let text = String::from("Asdasd asdabc asd ewabcabc");
    let occurences = search(b"abc", text.as_bytes());

    println!("Pattern found at:");
    for i in occurences {
        println!("{}", i);
    }
}
