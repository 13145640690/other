/*
********************************************************************************
* �ļ���     :  main.c
* ����       : 
 
* �汾     ����            ����            ˵��
* V1.0    ũ����        2014/04/21       ��ʼ�汾
********************************************************************************
*/


/*******************************************************************************
* ������	: msOSInsertFileHeader
* ����	    : �����ļ�ע��
* �������  : ��
* ���ز���  : ��
*******************************************************************************/
macro msOSInsertFileHeader()
{
    // get aurthor name
    szMyName = getenv(MYNAME)
    if (strlen(szMyName) <= 0)
    {
        szMyName = "ũ����"
    }

    // get company name
    szCompanyName = getenv(MYCOMPANY)
    if (strlen(szCompanyName) <= 0)
    {
        szCompanyName = szMyName
    }

    // get time
    szTime = GetSysTime(True)
    Day = szTime.Day
    Month = szTime.Month
    Year = szTime.Year
    if (Day < 10)
    {
        szDay = "0@Day@"
    }
    else
    {
        szDay = Day
    }
    if (Month < 10)
    {
        szMonth = "0@Month@"
    }
    else
    {
        szMonth = Month
    }

    // get file name
    hbuf = GetCurrentBuf()
    szpathName = GetBufName(hbuf)
    szfileName = GetFileName(szpathName)
    nlength = StrLen(szfileName)

    // assemble the string
    hbuf = GetCurrentBuf()
    
    InsBufLine(hbuf, 0, "")
    InsBufLine(hbuf, 1, "/*******************************************************************************")
    InsBufLine(hbuf, 2, "* �ļ��� : @szfileName@")
    InsBufLine(hbuf, 3, "")
    InsBufLine(hbuf, 4, "* �汾     ����            ����            ˵��")
    InsBufLine(hbuf, 5, "* V1.0    @szMyName@        @Year@/@szMonth@/@szDay@       ��ʼ�汾")
    InsBufLine(hbuf, 6, "")
    InsBufLine(hbuf, 7, "* ����   : MCU:      ����:    MHz")
    InsBufLine(hbuf, 8, "           ")
    InsBufLine(hbuf, 9, "*******************************************************************************/")
    InsBufLine(hbuf,10, "")


    // put the insertion point
    SetBufIns(hbuf, 7, 16) //���ù��ͣ��λ��
}

/*******************************************************************************
* ������	: msOSInsertFunctionHeader
* ����	    : ���뺯��ע��
* �������  : ��
* ���ز���  : ��
*******************************************************************************/
macro msOSInsertFunctionHeader()
{
    AuthorName = "fast_sky\@sina.com"
    hwnd = GetCurrentWnd()
    lnFirst = GetWndSelLnFirst(hwnd)
    hbuf = GetCurrentBuf()//��������ռ䣬Get a handle to the current file buffer and the name

    InsBufLine(hbuf, lnFirst+0, "")
    InsBufLine(hbuf, lnFirst+1, "/*******************************************************************************")
    InsBufLine(hbuf, lnFirst+2, "* �������� : ")
    InsBufLine(hbuf, lnFirst+3, "* �������� : ")
    InsBufLine(hbuf, lnFirst+4, "* ������� : ")
    InsBufLine(hbuf, lnFirst+5, "* ���ز��� : ")
    InsBufLine(hbuf, lnFirst+6, "* ������� : ")
    InsBufLine(hbuf, lnFirst+7, "      ")
    InsBufLine(hbuf, lnFirst+8, "*******************************************************************************/")
    InsBufLine(hbuf, lnFirst+9, "")

    SetBufIns(hbuf, lnFirst+10, 0) //���ù��ͣ��λ��

}


/*******************************************************************************
* ������	: msOSInsertHFileBanner
* ����	    : ����*.hͷ�ļ����ؼ��������궨��
* �������  : ��
* ���ز���  : ��
*******************************************************************************/
macro msOSInsertHFileBanner()
{
    // get file name
    hbuf = GetCurrentBuf()
    szpathName = GetBufName(hbuf)
    szfileName = GetFileName(szpathName)
    szfileName = toupper(szfileName)

    // create banner
    banner = "__"
    nlength = strlen(szfileName)
	
    i=0
    while (i < nlength)
    {
        if (szfileName[i] == ".")
        {
            banner = cat(banner, "_")
        }
        else
        {
            banner = cat(banner, szfileName[i])
        }

        i = i+1
    }

    banner = cat(banner, "__")

    // print banner
    hwnd = GetCurrentWnd()
    lnFirst = GetWndSelLnFirst(hwnd)
    lnLast = GetWndSelLnLast(hwnd)
	 
    hbuf = GetCurrentBuf()
    InsBufLine(hbuf, lnFirst, "")
    InsBufLine(hbuf, lnFirst+1, "")
    InsBufLine(hbuf, lnFirst+2, "#ifndef @banner@")
    InsBufLine(hbuf, lnFirst+3, "#define @banner@")
    InsBufLine(hbuf, lnFirst+4, "")
    InsBufLine(hbuf, lnFirst+5, "")
    InsBufLine(hbuf, lnFirst+6, "")
    InsBufLine(hbuf, lnFirst+7, "")
    InsBufLine(hbuf, lnFirst+8, "")
    InsBufLine(hbuf, lnFirst+9, "#endif /*@banner@*/")
    InsBufLine(hbuf, lnFirst+10, "")

    SetBufIns(hbuf, lnFirst+11, 0)
}

/*==================================================================
* Function	: GetFileName
* Description	: get file name from path
*			  
* Input Para	: pathName	: path string
			  
* Output Para	: None
			  
* Return Value: name		: file name
==================================================================*/

macro GetFileName(pathName)
{
    nlength = strlen(pathName)
    i = nlength - 1
    name = ""
    while (i + 1)
    {
        ch = pathName[i]
        if ("\\" == "@ch@")
            break
        i = i - 1
    }
    i = i + 1
    while (i < nlength)
    {
        name = cat(name, pathName[i])
        i = i + 1
    }

    return name
}
/*******************************************************************************
* ������	: MultiLineComment
* ����	    : ��ݼ�����ע�͵ĺ궨�壬��Ϊ:MultiLineComment
* �������  : ��
* ���ز���  : ��
*******************************************************************************/
macro msOSMultiLineComment()
{
    hwnd = GetCurrentWnd()
    selection = GetWndSel(hwnd)
    LnFirst = GetWndSelLnFirst(hwnd)      //ȡ�����к�
    LnLast = GetWndSelLnLast(hwnd)      //ȡĩ���к�
    hbuf = GetCurrentBuf()
  
    if(GetBufLine(hbuf, 0) == "//magic-number:tph85666031"){
        stop
    }
  
    Ln = Lnfirst
    buf = GetBufLine(hbuf, Ln)
    len = strlen(buf)
  
    while(Ln <= Lnlast) {
        buf = GetBufLine(hbuf, Ln)  //ȡLn��Ӧ����
        if(buf == ""){                    //��������
            Ln = Ln + 1
            continue
        }
  
        if(StrMid(buf, 0, 1) == "/") {       //��Ҫȡ��ע��,��ֹֻ�е��ַ�����
            if(StrMid(buf, 1, 2) == "/"){
                PutBufLine(hbuf, Ln, StrMid(buf, 2, Strlen(buf)))
            }
        }
  
        if(StrMid(buf,0,1) != "/"){          //��Ҫ���ע��
            PutBufLine(hbuf, Ln, Cat("//", buf))
        }
        Ln = Ln + 1
    }
  
    SetWndSel(hwnd, selection)
}
