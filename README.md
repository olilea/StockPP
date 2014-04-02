StockPP
=======

A port of my jStock game into C++:
A small game to play with virtual money on the real stock market from within a Unix terminal

No dependencies required, simply:

```shell
make
./Stock++
```

TODO:

- Replace list<Stock> stocksHeld in account.cpp to be a list of dynamically allocated Stock instance pointers (list<*Stock>).
- Modify all methods that use the original list<Stock>
- Add methods in user interface for buying and selling stock
