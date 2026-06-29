# a clock has 360
# each hour is 360/12
# each minute is 360/12/5

class Solution(object):
    def angleClock(self, hour, minutes):
        hour_angle = (hour % 12) * (360.0/12) + (minutes/60.0) * (360.0/12)
        minutes_angle = (minutes / 60.0) * 360.0

        diff = abs(hour_angle-minutes_angle)
        return min(360-diff, diff)