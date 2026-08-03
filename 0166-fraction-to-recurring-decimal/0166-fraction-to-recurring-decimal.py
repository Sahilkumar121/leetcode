class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return "0"

        result = ""

        if numerator * denominator < 0:
            result += "-"

        absNumerator = abs(numerator)
        absDenomerator = abs(denominator)

        result += str(absNumerator // absDenomerator)
        remainder = absNumerator % absDenomerator

        if remainder == 0:
            return result

        result += "."

        mp = defaultdict(int)

        while remainder != 0:
            if remainder in mp:
                result = result[: mp[remainder]] + "(" + result[mp[remainder] :] + ")"
                return result

            mp[remainder] = len(result)
            remainder *= 10

            digit = remainder // absDenomerator
            result += str(digit)

            remainder = remainder % absDenomerator

        return result