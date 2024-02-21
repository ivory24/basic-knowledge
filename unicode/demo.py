import unicodedata

s = "⽂文"
s_bytes = s.encode('utf-8')
print(s_bytes)

normalized_s = unicodedata.normalize('NFKC', s)
normalized_s_bytes = normalized_s.encode('utf-8')
print(normalized_s_bytes)