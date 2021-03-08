스타일 시트(Style sheet)
문서의 외형을 구체적으로 명시하기 위한 문장의 집합
웹페이지 구성 요소에 크기, 색깔 등의 스타일을 일괄적으로 적용

스타일 시트의 장점
문서의 내용에서 스타일 정보가 분리
똑같은 스타일 정보를 반복할 필요 없음
스타일 변경시 스타일 정보 만을바꾸어주면 되므로 변경이 용이

스타일 시트 종류

스타일 시트 정의 문법 종류

CSS(Cascading Style Sheet)
스타일 속성, 속성값으로 스타일 제어
<style type="text/css">(CSS가 표준이여서 <style>만 사용가능)

JSSS(JavaScript Syle Sheet)
Java script로 스타일 정보 제어
<style type="text/JavaScript">

CSS: Cascadion Style Sheet

CSS의 형식
선택자(selector): 속성을 넣고싶은 태그
속성종류(Property): color, font-size, vackground-color
속성값(Value): blue, 12px, navy

속성의 상속
어떠한 태그에 지정된 속성은 그 안에 사용된 태그에도 적용됨

CSS스타일 정보 삽입 방법

1. 웹페이지 <HEAD> 태그 내 정의
웹 페이지에 스타일 정보를 포함시키는 역할
head태그 내에서만 사용 가능

2. 인라인 스타일 정의
body부분에 사용된 태그 내에 속성으로 정의

3. 별도의 style sheet삽입
stylesheet문서의 url로부터 스타일 정보를 읽어 웹 페이지에 적용
확장자를 .css로 해서 파일을 만든다
서버 /var/www/html 디렉토리 위치로 옮긴다
<link rel="STYLESHEET" type="text/css" href="http://ip주소/filename.css>







