# You have n servers with IDs, "s1", "s2", ..., "sn".
# The system processes a sequence of log entries,
# where each entry is formatted as:
# "<server_id> <status>", where the status is either "success" or "error".

# For each server, track its consecutive errors:
# if a server records 3 "error" logs in a row, it is considered faulty 
# and is replaced (the replacement server keeps the same ID).

# After a replacement, that server's consecutive error count resets to 0.
# A "success" log also resets that server's consecutive error count to 0.

# You task is to determine the total number of server replacements that occur
# while processing all log entries.

# Example:
# Suppose n = 2 and 
# logs = ["s1 error", "s1 error", "s2 error", "s1 error", "s1 error", "s2 success"]
# Output: 1

# Explanation:
# 1. s1 logs first error: [error]
# 2. s1 logs second error: [error, error]
# 3. s2 logs first error: [error]
# 4. s1 logs third error: [error, error, error], s1 is replaced
# 5. s1(new) logs first error: [error]
# 6. s2 logs a success: []

# Only server 1 is replaced once.

class Solution(object):
    def getTotalServerReplaced(self, logs):
        if not logs:
            return 0

        error_counts = {} # server_id : error_counts
        replacements = 0
        for log in logs:
            server_id, server_status = log.split(' ')

            if server_status == "error":
                error_counts[server_id] = error_counts.get(server_id, 0)+1
                if error_counts[server_id] == 3:
                    error_counts[server_id] = 0
                    replacements += 1
            else:
                error_counts[server_id] = 0
        return replacements

