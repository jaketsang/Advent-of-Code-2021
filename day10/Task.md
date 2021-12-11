Part 1:
- corrupted line: start annd end characters don't match
- {([([}{[]{[(

Example
{([(<{}[<>[]}>{[]{[(<()>
            ^ character should be ], the only starting bracket that matches } is the 
            { at the very beginning which cannot be closed off since there are other 
            unclosed brackets between them

[[<[([]))<([[{}[[()]]]
        ^ should be ]

[{[{({}]{}}([{[{{{}}([]
       ^ should be )

Scoring
- 1st illegal character 
- ) = 3
- ] = 57
- } = 1197
- > = 25137

for closing bracket checks, make note of the most recent stsarting bracket, and ssee if it matches, as it cannot be used to cut off others
- ((<<)> = ) is invalid  

Part 2:
- delete all corrcupt lines
- find the sequence of closing characters that complete all open chucnks 