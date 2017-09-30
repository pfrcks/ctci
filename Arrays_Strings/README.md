### Notes

#### Is Unique (+)

The tricky solution involves setting the bit of a 32 bit integer based on its distant from 'a'. Sadly since there are only 32 bits, this method can only be used for alphabets.

#### Check Permutation

* If the two strings are random permutation just create two hash and check for equivalence. The hash array stores counts of occurence. This is an O(n) approach with 2n extra space.
* If don't want to waste space for hash array we can sort both the given strings and compare. This is an O(nlogn) approach.

#### URLify (+)

Use the true length and the length of the string and iterate in reverse moving each character to the end and inserting %20 along the way.

#### Palindrome Permutation

Create a count hash of the string. If number of occurences of characters is odd for more than one character return false.

#### One Away (+)

```
- if diff(len of strings) > 1 then return false`
- if diff(len of strings) == 0 then iterate over strings allowing only one mismatch`
- if diff(len of strings) == 1 then if characters match continue, if mismatch move in the larger string. If mismatch again return false`
```

#### String Compression

This is also known as [Run Length Encoding](https://en.wikipedia.org/wiki/Run-length_encoding).
```
do
	copy the character to the destination string
	count the reoccurences
	copy the count to the destination string
	repeat for the next character
done
```

_Note_ : The maximum length of the destination array can be 2*length of original array. This occurs when all characters are unique.

#### Rotate Matrix

- [ ] Understand and implement

* Trick Method

```
- Take the transpose of the matrix
- Reverse the column entries
```


#### Zero Matrix

```
- Initialize markers if first row and column has a zero.
- Use the first row to keep track of occurence of zero in rows
- Use the first column to keep track of occurence of zero in columns
- If Mat[i][0] is zero the whole row is set to zero, if Mat[0][j] is zero then whole column is set to zero
- Check values of markers and initiaze first row or column to zero if set
```

#### String Rotation(+)

```
- create a new string which is simply string1 appended to itself
- string2 has to be a substring of the new string for it to be a rotation of string1
```
