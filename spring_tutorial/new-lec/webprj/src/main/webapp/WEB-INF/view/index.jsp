<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>

<head>
    <title>�ڵ� �������� ����� ���� �¶��� ���� �ý���</title>
    <meta charset="UTF-8">
    <title>�������׸��</title>

    <link href="/css/layout.css" type="text/css" rel="stylesheet" />
    <link href="/css/index.css" type="text/css" rel="stylesheet" />
    <script>
    
    </script>
</head>

<body>
    <!-- header �κ� -->

    <header id="header">
        
        <div class="content-container">
            <!-- ---------------------------<header>--------------------------------------- -->

            <h1 id="logo">
                <a href="/index.html">
                    <img src="/images/logo.png" alt="����ó �¶���" />

                </a>
            </h1>

            <section>
                <h1 class="hidden">���</h1>

                <nav id="main-menu">
                    <h1>���θ޴�</h1>
                    <ul>
                        <li><a href="/guide">�н����̵�</a></li>

                        <li><a href="/course">���¼���</a></li>
                        <li><a href="/answeris/index">AnswerIs</a></li>
                    </ul>
                </nav>

                <div class="sub-menu">

                    <section id="search-form">
                        <h1>���°˻� ��</h1>
                        <form action="/course">
                            <fieldset>
                                <legend>�����˻��ʵ�</legend>
                                <label>�����˻�</label>
                                <input type="text" name="q" value="" />
                                <input type="submit" value="�˻�" />
                            </fieldset>
                        </form>
                    </section>

                    <nav id="acount-menu">
                        <h1 class="hidden">ȸ���޴�</h1>
                        <ul>
                            <li><a href="/index.html">HOME</a></li>
                            <li><a href="/member/login.html">�α���</a></li>
                            <li><a href="/member/agree.html">ȸ������</a></li>
                        </ul>
                    </nav>

                    <nav id="member-menu" class="linear-layout">
                        <h1 class="hidden">���޴�</h1>
                        <ul class="linear-layout">
                            <li><a href="/member/home"><img src="/images/txt-mypage.png" alt="����������" /></a></li>
                            <li><a href="/notice/list"><img src="/images/txt-customer.png" alt="������" /></a></li>
                        </ul>
                    </nav>

                </div>
            </section>

        </div>
        
    </header>


    <!-- --------------------------- <body> --------------------------------------- -->

    <!-- content �κ� -->



    <div id="visual" class="">
        <div class="content-container">
            <h2 class="hidden">�ű� ���¸��</h2>
            <!-- <ul class="mov-button">
			<li class="prev-button">����</li>
			<li class="next-button">����</li>
		</ul> -->
            <ul class="banner">


                <li class="banner1">
                    <a href="customer/event/1">
                        <img src="admin/board/event/1/banner-java.png" data-id="1" style="cursor: pointer;" />
                    </a>
                </li>

            </ul>



            <ul class="banner-button-list" style="color:#ffff00; font-size:20px;position:absolute; left:10px; bottom:5px; z-index: 100px; display: flex; flex-direction: row;">
                <li></li>
            </ul>

        </div>

    </div>
    <div id="notice">
        <div class="content-container">
            <span class="title">����ε� ���������� ������ <span style="color:yellow;font-size:15px;">IT PROFESSIONAL <span style="color:#00ffff;">NEW</span>
                    ONLINE <span style="color:#00ffff;">LECTURE</span> MARKET</span></span>
            <!--<a class="detail-button">�ڼ���</a>-->
        </div>
    </div>
    <!-- ----- �������� �� ------------------------------------------------------------------------------ -->
    <div id="information">
        <div class="content-container">
            <section class="guide">
                <h1 class="title">���� �÷��̾� ����� �ȳ�</h1>
                <div class="margin-top">
                    <a href="customer/faq/1"><img src="images/customer/installInfo.png" /></a>
                </div>
                <!-- <div>
            2
            </div>
            <div>
            3
            </div> -->
            </section>
            <section class="course-info">
                <h1 class="title text-center">����ó ���̺긮�� ���� ����</h1>
                <ul class="list">
                    <li>���� ���� ������ �����ϴ�.</li>
                </ul>
            </section>
            <section class="notice">
                <h1 class="title">��������</h1>
                <ul class="list margin-top">

                    <li>
                        <span class="notice-title">
                            <a href="notice/detail.html">������ 8�������� ���� �ڵ�</a>
                        </span>
                        <span>2019-08-18</span>
                    </li>

                    <li>
                        <span class="notice-title">
                            <a href="notice/detail.html">������ DI ���� �ڵ�</a>
                        </span>
                        <span>2019-08-15</span>
                    </li>

                    <li>
                        <span class="notice-title">
                            <a href="notice/detail.html">������ 9�� �� ������� ���� �ȳ�</a>
                        </span>
                        <span>2019-06-11</span>
                    </li>

                    <li>
                        <span class="notice-title">
                            <a href="notice/detail.html">����ó ���� ���� ��� �ȳ�</a>
                        </span>
                        <span>2019-05-24</span>
                    </li>

                    <li>
                        <span class="notice-title">
                            <a href="notice/detail.html">�ڹ� �������� ���α׷��� ���� ���� ����</a>
                        </span>
                        <span>2019-04-24</span>
                    </li>

                </ul>
            </section>
        </div>
    </div>

    <!-- ----- Ŀ�´�Ƽ ���� �� -------------------------------------------------------------------------------------------- -->



    <!-- ----- Ŀ�´�Ƽ ���� �� -------------------------------------------------------------------------------------------- -->
    <!-- <div class="margin-top">
	<div style="height: 170px; margin-top:10px;" class="content-container border">
	</div>
</div> -->

    <!-- ----- ���� ��� ���� �� --------------------------------------------------------------------------------------------------------- -->
    <main id="course">
        <section class="content-container list list-horizontal list-course list-course-index">
            <h1>�¶��� <span class="color-orange">�ܰ� ����</span></h1>
            <div>
               
            </div>

            <ul>
                <!-- <li class="item-course normal new">
                    <div>
                        <a href="course/16"><img src="images/course/landing page.png" /></a>
                        
                    </div>
                    <div>
                        <div>
                            <a href="course/16"><span class="text-strong text-ellipsis">���� ���α׷��Ӱ� �Ǳ� ���� ��������</span></a>
                        </div>
                        <div class="price">
                            <span class="normal ">
                                <span class="text-orange text-strong">
                                    0
                                </span> ��
                            </span> <span class="event">



                            </span>
                        </div>
                        <div class="footer text-strong">
                            <span class="writer">������ : newlec </span>
                            <span class="update">������ : 2019-09-07
                            </span>
                        </div>
                    </div>
                </li>
                <li class="item-course normal new">
                    <div>
                        <a href="course/10"><img src="images/course/html5.png" /></a>
                        
                    </div>
                    <div>
                        <div>
                            <a href="course/10"><span class="text-strong text-ellipsis">�� ǥ�ر���� �� �ۺ��� HTML5 ��</span></a>
                        </div>
                        <div class="price">
                            <span class="normal ">
                                <span class="text-orange text-strong">
                                    45,000
                                </span> ��
                            </span> <span class="event">



                            </span>
                        </div>
                        <div class="footer text-strong">
                            <span class="writer">������ : newlec </span>
                            <span class="update">������ : 2019-09-07
                            </span>
                        </div>
                    </div>
                </li>


                <li class="item-course normal event">
                    <div>
                        <a href="course/8"><img src="images/course/oracle.png" /></a>
                       
                    </div>
                    <div>
                        <div>
                            <a href="course/8"><span class="text-strong text-ellipsis">Oracle SQL ���α׷���</span></a>
                        </div>
                        <div class="price">
                            <span class="normal deprecated">
                                <span class="text-gray">
                                    44,000
                                </span> ��
                            </span> <span class="event">


                                <span class="color-red text-strong">
                                    0
                                </span>��


                            </span>
                        </div>
                        <div class="footer text-strong">
                            <span class="writer">������ : newlec </span>
                            <span class="update">������ : 2019-09-07
                            </span>
                        </div>
                    </div>
                </li>
                <li class="item-course normal normal">
                    <div>
                        <a href="course/7"><img src=images/course/spring.png" /></a>
                       
                    </div>
                    <div>
                        <div>
                            <a href="course/7"><span class="text-strong text-ellipsis">������ 3.x MVC �� ���α׷���</span></a>
                        </div>
                        <div class="price">
                            <span class="normal ">
                                <span class="text-orange text-strong">
                                    33,600
                                </span> ��
                            </span> <span class="event">



                            </span>
                        </div>
                        <div class="footer text-strong">
                            <span class="writer">������ : newlec </span>
                            <span class="update">������ : 2019-09-07
                            </span>
                        </div>
                    </div>
                </li> -->
                <li class="item-course normal event">
                    <div>
                        <a href="course/2"><img src="images/course/java.png" /></a>                        
                    </div>
                    <div>
                        <div>
                            <a href="course/2"><span class="text-strong text-ellipsis">�ڹ� ���α׷���</span></a>
                        </div>
                        <div class="price">
                            <span class="normal deprecated">
                                <span class="text-gray">
                                    22,000
                                </span> ��
                            </span> <span class="event">


                                <span class="color-red text-strong">
                                    0
                                </span>��


                            </span>
                        </div>
                        <div class="footer text-strong">
                            <span class="writer">������ : newlec </span>
                            <span class="update">������ : 2019-09-07
                            </span>
                        </div>
                    </div>
                </li>


            </ul>

            <div class="more">
                <!-- <span class="border padding">�ܰ� ���� ��� ������</span> -->
            </div>
        </section>

        <!-- ------- �¶��� ��Ű�� ���� ------------------------------------------------------------------------------------------------- -->

        <div class="content-container">
            <h3 class="-text- center green bold -margin- top">���¾�ü</h3>
            <ul class="-list- horizontal center -margin- bottom top b20">
                <li><a target="_blank" href="http://www.notepubs.com"><img src="images/notepubs.png" alt="��Ʈ�ེ" /></a></li>
                <li><a target="_blank" href="http://www.namoolab.com"><img src="images/namoolab.png" alt="������������" /></a></li>                
               
            </ul>
        </div>
    </main>
    <script>

    </script>




    <!-- ------------------- <footer> --------------------------------------- -->



    <footer id="footer">
        <div class="content-container">
            <h2 id="footer-logo"><img src="images/logo-footer.png" alt="ȸ������"></h2>

            <div id="company-info">
                <dl>
                    <dt>�ּ�:</dt>
                    <dd>����Ư���� </dd>
                    <dt>�����ڸ���:</dt>
                    <dd>admin@newlecture.com</dd>
                </dl>
                <dl>
                    <dt>����� ��Ϲ�ȣ:</dt>
                    <dd>111-11-11111</dd>
                    <dt>��� �Ǹž�:</dt>
                    <dd>�Ű��� 1111 ȣ</dd>
                </dl>
                <dl>
                    <dt>��ȣ:</dt>
                    <dd>����ó</dd>
                    <dt>��ǥ:</dt>
                    <dd>ȫ�浿</dd>
                    <dt>��ȭ��ȣ:</dt>
                    <dd>111-1111-1111</dd>
                </dl>
                <div id="copyright" class="margin-top">Copyright �� newlecture.com 2012-2014 All Right Reserved.
                    Contact admin@newlecture.com for more information</div>
            </div>
        </div>
    </footer>
</body>

</html>