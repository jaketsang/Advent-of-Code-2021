Part 1:
- diagnostic report
    - binary numbers

- gamma rate = made up of the mosts common bit in that (column) position e.g. right most bit = most common bit in 1st bit of all binary numbers
- epsilon rate = least common bit (ie opposite of gamma)
- power consumpotion= gamma * epsilon (decimal value not binary)


Part 2:
- life support = oxygen generator * CO2 scruber
- consider just 1st bit of those numbers
- keep numbers selected by bit criteria, discard rest
- if 1 number left, stop -> this is the rating
- otherwise repeat, considering next bit to the right

Bit crietria
- oxygen rating: most common value in current position. If equally common, keep values with a 1 in the position being considered (e.g if 1st bit value, keep values with 1)
- c02: least common value in current bit position, keep only numbers with that bit in that position. If equally commonn keep values with 0 in the position beingn considered


10110
10111
10101


74875