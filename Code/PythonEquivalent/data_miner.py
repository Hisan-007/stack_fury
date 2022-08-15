from bs4 import BeautifulSoup
import requests
import urllib3

#disable unnecessary warnings to the console
urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

url_begin= "https://stackoverflow.com/questions/tagged/java?tab=newest&page="
url_end = "&pagesize=50"

base_url = "https://stackoverflow.com"
counter = 214;

for i in range(counter,4000):
        url = url_begin+str(i)+url_end
        try:
                r = requests.get(url, verify = False)
        except:
                continue
        soup = BeautifulSoup(r.content, 'lxml')
        list_of_tags = soup.find_all('div', class_='summary')
        file = open("E:\\University_stuff\\semester_3\\data_structures\\end_semester_project\\AnswerBase\\links_base.txt", "a", encoding="utf-8")
        for j in list_of_tags:
                file.write(base_url+j.h3.a['href']+'\n')
        file.close()
        counter+=1
        print(counter)
