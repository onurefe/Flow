from json import loads
from math import acos, pi
import matplotlib.pyplot as plt


def plot(path):
    with open(path, "r") as infile:
        dat = loads(infile.read())
        y = []
        for i in range(0, len(dat["freqs_khz"])):
            inner = 8 * dat["avr_cha_a_b_mul"][i] / (dat["cha_a"][i] * dat["cha_b"][i])
            y.append(-180.0 * acos(inner) / pi)

        plt.xlabel("Frequency(KHz)")
        plt.ylabel("Phase(Degrees)")
        plt.plot(dat["freqs_khz"], y)
        plt.show()

plot("rxsensor.json")
