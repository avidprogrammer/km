N = 6 
seq = []
seq_end_len = [1] * N
subseq = []

for idx in range(N):
  seq.append(int(raw_input()))

for xidx in range(N):
  best_yidx = None
  for yidx in range(xidx):
    if seq[yidx] < seq[xidx] and \
       (seq_end_len[yidx] + 1) > seq_end_len[xidx]:
      seq_end_len[xidx] = seq_end_len[yidx] + 1
      best_yidx = yidx
  if best_yidx != None:
    this_subseq = subseq[best_yidx] + [seq[xidx]]
  else:
    this_subseq = [seq[xidx]]
  subseq.append(this_subseq)

print seq_end_len
print subseq
  
