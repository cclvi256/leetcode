pub fn can_construct(ransom_note: String, magazine: String) -> bool {
    let mut count = vec![0; 26];
    for i in magazine.chars() {
        count[i as usize - 'a' as usize] += 1;
    }
    
    for i in ransom_note.chars() {
        count[i as usize - 'a' as usize] -= 1;
        if count[i as usize - 'a' as usize] < 0 {
            return false;
        }
    }

    true
}
