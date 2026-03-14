import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Scanner;
import org.json.JSONArray;
import org.json.JSONObject;

class Result 
{
    public static int healthCheckup(int lowerlimit, int upperlimit) 
    {
        int count = 0;
        int currentPage = 1;
        int totalPages = 1;

        try 
        {
            while (currentPage <= totalPages) 
            {
                // open connection to the API
                String urlStr = "https://jsonmock.hackerrank.com/api/medical_records?page=" + currentPage;
                HttpURLConnection conn = (HttpURLConnection) new URL(urlStr).openConnection();
                conn.setRequestMethod("GET");

                // read response body into a string
                Scanner scanner = new Scanner(conn.getInputStream());
                StringBuilder sb = new StringBuilder();
                while (scanner.hasNextLine()) {
                    sb.append(scanner.nextLine());
                }
                scanner.close();

                // parse JSON response
                JSONObject root = new JSONObject(sb.toString());

                // update total pages from first response
                totalPages = root.getInt("total_pages");

                // iterate over records
                JSONArray data = root.getJSONArray("data");
                for (int i = 0; i < data.length(); i++) 
                {
                    JSONObject record = data.getJSONObject(i);
                    int diastole = record
                        .getJSONObject("vitals")
                        .getInt("bloodPressureDiastole");

                    if (diastole >= lowerlimit && diastole <= upperlimit) 
                    {
                        count++;
                    }
                }

                currentPage++;
            }
        } 
        catch (Exception e) 
        {
            e.printStackTrace();
        }

        return count;
    }
}