
def fractional_knapsack(values,weights,capacity):


    ratios = [(v/w,w) for v,w in zip(values,weights)]
    ratios.sort(reverse=True)
    total_value = 0

    for ratio,w in ratios:
        if capacity >= w:
            total_value += ratio * w
            capacity -= w
        else:
            total_value += ratio * capacity
            break

    return total_value











values = [60,100,120]
weights = [10,20,30]
knapsack_quantity = 50

max_value = fractional_knapsack(values,weights,knapsack_quantity)
print("max_vsalue:",max_value)