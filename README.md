<p align = "center">
<img src = "Logo.png"> <br>
<a href="#steps">Steps</a> • <a href="#explanation">Explanation</a> • <a href="#viability">Viability</a> • <a href="#practical-implementation">Practical Implementation</a> • <a href="#lockencryption">Encryption</a> • <a href="#unlockdecryption">Decryption</a> 
</p>

---
Steps
---

- First select two distinct prime numbers, say p and q. (preferably big to score a decent level of security)

> Can be generated using a primality test. <br>
> Fermat’s test can be used, although practically Miller Rabin’s test is more sought after.

- Take their product as N i.e. N = p\*q, which is the *modulus* of both the keys.

- Then calculate the **Euler’s totient** for the above, given by ϕ(N) = (p-1)\*(q-1). 

- Proceed by choosing a Public Key e such that 1 < e < ϕ(N) and e is coprime with N and ϕ(N) => e must be odd.

- Choose a corresponding Private Key d such that it satisfies the equation or e\*d mod ϕ(N) = 1. 

> d is the multiplicative inverse of e modϕ(N). <br>
> The Public Key is (e, N) and the Private Key is (d, N). <br>
> As e was chosen, e is much smaller than d => encrypting a message using RSA is much faster than decrypting it. 

- Ciphertext is calculated using the equation c = m<sup>e</sup> mod N, where m is the message to be encrypted.

- With the help of c and d thus obtained, we can decrypt the message using m = c<sup>d</sup> mod N.

Explanation
-------

The Euler’s totient φ(N) of a positive integer N greater than 1 is defined to be the number of positive integers less than N that are coprime with N. (φ(1) is defined to be 1) <br>
When N is prime, ϕ(N) = N-1, as in the case of Fermat’s theorem.
Plaintext and ciphertext are integers between 0 and N-1 for some N.

- Encryption and decryption are of the following form, for some plaintext M and ciphertext C: <br>
    - C = M<sup>e</sup>(mod N) 
    - M = C<sup>d</sup>(mod N) = (M<sup>e</sup>)<sup>d</sup>(mod N) = M<sup>ed</sup>(mod N)

- Each communicating entity has one public-key (e, N) or private-key (d, N) pair, where both e and d are in fact the multiplicative inverse (modϕ(N)) of the other. 

    - e and d are inverses (modϕ(N)), or ed ≡ 1 (modϕ(N))
    - ed = 1 + kϕ(N), for some k.
    - M<sup>ed</sup>(mod N) = M<sup>1 + kϕ(N)</sup>(mod N) = M<sup>1</sup> x (M <sup>ϕ(N)</sup>)<sup>k</sup>(mod ϕ(N)) = M<sup>1</sup> x 1<sup>k</sup>(mod N) = M. (Euler’s theorem)

Therefore, to decrypt a ciphertext C = M<sup>ed</sup>(mod N), we only need to calculate C<sup>d</sup>(mod N), since we know C = M<sup>e</sup>(mod N) => C<sup>d</sup>(mod N) = M<sup>ed</sup>(mod N) => C<sup>d</sup>(mod N) = M. (with M<sup>ed</sup>(mod N) being M)

Viability
-------

The RSA cryptosystem is based on the theorem which implies that the inverse of the function a->a<sup>e</sup> mod N (where e is the Public Encryption exponent) is the function b->b<sup>d</sup> mod N, (where d is the Private Decryption exponent) which provides the difficulty of computing ϕ(N) without knowing the factorization of N. (and thus the difficulty of computing d arises in addition)

This can only be solved by factorizing N (since every number is essentially a product of primes) and only the owner of the private key knows the factorization (primes p and q whose product yields N). This ‘factoring problem’ is the security point, with greater chances of the encryption to be secure for large values of N, or for large primes considered. The fact that only N is publicly disclosed, along with the given difficulty to factor large numbers (it is computationally infeasible to factor a large value of N to get d) gives the guarantee that no one else knows the factorization and the encrypted message, thus making it viable.

Practical Implementation
-------

Given that there are multiple factors to be considered in modern-day cryptographic routines in order to establish a deeper level of security, its best to create specific implementations than to use the generalized ones or the toy implementations.

For general use, the length for the 2 primes considered (p and q) should be preferably around 2<sup>11</sup> bits (2048) or more, which results in values (N) greater than 2<sup>12</sup> (4096) bits upon their multiplication (p\*q). This ensures a tight encryption which is seemingly impossible to decrypt even when provided with massive computing resources (although completely possible to breach/bruteforce every combination if we were to leverage the power of supercomputers) for a large span of time. 

Hence, the RSA algorithm is quite feasible in general, apart from its primary downside of being much slower than symmetric cryptosystems. There are better alternatives (faster and more secure encryption schemes) such as elliptic curve cryptosystems, but then again, quantum computing could overcome that as well. Eventually nothing seems that secure, or has a counter-measure in the long run. 

-------

:lock:Encryption
-------
| Input: RSA public key (e, N), plaintext m ∈ [0, N-1] | Output: Ciphertext c, (Compute c = m<sup>e</sup>(mod N), return c) |
|---|---|

:unlock:Decryption
-------
| Input: RSA private key (d, N), ciphertext c | Output: Plaintext m,  (Compute m = c<sup>d</sup>(mod N), return m) |
|---|---|
-------

Instructions
-------
- SEND MESSAGE TO FRIEND
> 1).Get Encryption Key from friend and copy only the parentheses : (e, N).
> 2).Choose option 2 (Encrypt Message), press CTRL+V to paste the Encryption Key and type in your message.
> 3).A file has been created next to your executable. Send it to your friend.

- READ FRIEND'S MESSAGE
> 1).Download friend's "EncryptedMessage" FILE and PLACE IT NEXT TO YOUR EXECUTABLE.
> 2).Choose option 3 (Decrypt Message). The Decryption Key will be copied from your "DecryptionKey" FILE and the decrypted message will appear.

- TIP : If you accidentally create a new Encryption/Decryption Key, you need to send the new Encryption Key to your friend.
- DO NOT CHANGE FILE NAMES.
