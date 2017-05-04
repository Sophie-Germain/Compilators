# Decaf Compiler

Based on Lawrence Rauchwerger Texas A&M Decaf project, which is based on Maggie Johnson's and Julie Zelenski's Stanford CS143 projects.

Spring 2017.

M.Sc. in Computer Science

ITAM, Mexico City. 


-------------------


## Deliverable 1
Preprocessor (macros and comments) and scanner implementation

#### Compilation
Run 'make'

#### Tests
./dcc < samples/test_file.frag > resultados.txt

## Deliverable 2
Parser
#### Compilation
Run 'make'

#### Tests
./dcc < samples/test_file.decaf &> resultados.txt
diff resultados.txt samples/test_file.out

## Deliverable 3,4
Semantic analysis
#### Compilation
Run 'make'

#### Tests
./dcc < samples/test_file.decaf &> resultados.txt
diff resultados.txt samples/test_file.out

## Deliverable 5
Code generation
#### Compilation
Run 'make'

#### Tests
./dcc < samples/test_file.decaf &> resultados.txt
diff resultados.txt samples/test_file.out


