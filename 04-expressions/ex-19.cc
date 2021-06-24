// ptr :: pointer to int
// vec :: vector<int>
// ival :: int

// Correct each of the following by using the _prefix_ increment operator.

// 1. Undefined!

// ptr != 0 && *ptr++

// Applying precedence. Just for clarity; it does not affect the order of
// evaluation of the subexpressions.

// ((ptr != 0) && (*(ptr++)))

// If (ptr++) is evaluated first, then this expression is equivalent to

// (((ptr + 1) != 0) && (*(ptr)))

// If (ptr != 0) is evaluated first, then this expression is equivalent to

// ((ptr != 0) && (*(ptr)))

// 2. Undefined!

// ival++ && ival

// Applying precedence.

// ((ival++) && ival)

// If (ival++) is evaluated first, then this expression is

// ((ival) && (ival + 1))

// If ival is evaluated first, then this expression is

// ((ival) && ival)

// 3. Undefined!

// vec[ival++] <= vec[ival]

// This is evaluated as

// vec[ival] <= vec[ival + 1]

// or

// vec[ival] <= vec[ival]
