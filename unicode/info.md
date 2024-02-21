# unicode统一编码
- unicode本身的编码，某些字符能够用多个合法的编码表示。但是在做embedding的过程中，为了减少偏差，希望所有字符在底层有相同的表示。具体含义可以运行demo.py 查看
- https://cloud.tencent.com/developer/article/1765762
- https://www.unicode.org/faq/normalization.html
- https://xobo.org/unicode-normalization-nfd-nfc-nfkd-nfkc/