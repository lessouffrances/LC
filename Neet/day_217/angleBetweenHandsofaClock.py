class Solution(object):
    def angleClock(self, hour, minutes):

        hour_angle = (hour % 12) * (360.0/12) + (minutes / 60.0) * (360.0/12)
        minutes_angle = (minutes / 60.0) * 360
        diff = abs(hour_angle - minutes_angle)

        # don't go beyond 180
        return min(diff, 360 - diff)

        
        