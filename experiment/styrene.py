styrene_ratio = 20.06 / (100 + 3 + 20.06 + 0.22)
def getYield(latex, monomer, stryrene_ratio=styrene_ratio):
    return monomer /(latex * stryrene_ratio) * 100

datasets = {}

if '__main__'== __name__:
    for i in range(4):
        datasets[70 + i * 5] = []
        for j in [1, 1.5, 2, 24]:
            latex, monomer = map(int, input(f"{70 + i * 5}도 {j}시간latex monomer").split())
            datasets[70 + i * 5].append({"latex": latex, "monomer": monomer, "yield": getYield(latex, monomer)})





