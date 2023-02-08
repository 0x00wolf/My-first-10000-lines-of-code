import random

def flip_coin():
    heads = 'h'
    tails = 't'
    coinflip = random.randint(0, 1)
    if coinflip == 0:
        return heads
    else:
        return tails

i = 0
heads = []
tails = []
while i < 555000:
    coinflip = flip_coin()
    if coinflip == 'h':
        heads.append(coinflip)
    else:
        tails.append(coinflip)
    i = i + 1
print('Heads was rolled %s times.', (len(heads)))
print('Tails was rolled %s times.', (len(tails)))
