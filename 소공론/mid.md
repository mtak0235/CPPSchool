# sw?

실행가능한 컴퓨터 명령어 (program) + 개발 문서

# IEEE/ACM에서 소프트웨어공학에서 다루는 지식 체계/주제를   정리해놓은 것을 무엇이라 부르는가?

software engineering body of knowledge(=SWEBOK)

# sw의 특성을 나열하라.

* complexity
* conformity
* changeability
* invisibility

✔3CI

# 마트에 진열된 물건처럼 누구든 사용할 수 있는 sw type은?

Commercial off the shelf (=COTS) 또는 package software

# software의 type은 뭐가 있나?

* custom sw
* package sw
* embedded sw
* SaaS (=sw as a service)

# swe가 뭐야?

sw 전 과정에 대한 체계적인 접근 방법

# swe가 생긴 이유가 뭐야?

* software crisis를 논하기 위해서. 
* 안정성 있는 sw 와 개발 비용을 줄이기 위해서

# swe가 해결하려는 문제가 뭐야?

* scale - 어떻게 하면 큰  sw를 만들 수 있을까
* quality and productivity
* consistency and reproducibility
* changes

# SWE가 문제에 접근하는 방법이 뭐야?

* sw 개발 절차
* sw 품질 보증
* 프로젝트 매니징

# sw 품질 기준을 뭐라고 불러?

SQuaRE (software product quality requirements and evaluation)

# SQuaRE의 기준으로 뭐가 있어?

* functionality
* reliability
* usability
* efficiency
* maintainability
* portability
* security
* compatibility

# SQA가 무엇의 약자야?

sw quality assurance

# 1960년대에 크고 복잡한 소프트웨어를 개발하면서 맞닥뜨린 고비용,   프로젝트 연기, 낮은 품질, 유지보수 등의 어려움을 가리키는 용어는?

software crisis



# 전통적인 알고리즘 기반 소프트웨어와 데이터 학습 기반   소프트웨어에 대해 비교 설명하시오.

알고리즘 기반은 입출력 절차를 사람이 짜기 때문에 정확한 결과가 보장되지만, 
데이터 학습 기반은 소프트웨어가 정해진 입출력을 학습해서 결과를 내기 때문에 정확한 결과를 보장할 수 없다. 

# sw process엔 뭐가 있어?

dev process와 support process가 있어.

# SDLC는 software development process와 같은 말이다. 

맞음. software development life cycle

# 전통적인 sw 활동은 어떤게 있어?

* requirements engineering 
* design
* implementation
* verification & validation

# 바람직한 sw process 의 특징이 뭐야?

*  predictability on costs and quality
* easy to test & maintain
* coping with change
* low cost in defect correction - 오류 초기 몰빵형

# 폭포수 모델의 특징과 장단점?

원샷 프로세스라서 뭘 만들어야 할지 미리 계획을 세울 수 있는 분야에 적합하다.

+) 과정이 심플하고, 각 단계에서 나와야 하는 산출물이 명확해서 예측이 쉽다.

-) 문서가 너무 많다. 예측하지 못한 상황에 대응하기 힘들다.

# Rapid prototyping model/ evolutionary model 의 특징과 장단점?

고갱님에게 이렇게 만드는게 맞는지 계속 프로토 타입으로 확인  받는다. 

+) 폭포 타입보다 즉각적인 대응

-) 언제 구현으로 넘어갈지 애매하다.

# spiral 모델의 특징과 장단점?

개발 전 과정에서 옵션을 나열하고, 위험 분석하고, 개발하고, 리뷰하고, 릴리즈 하고를 반복한다. 

+) 위험 감소,다음 사이클에 새 기능을 넣을 수 있다. 프로덕트가 일찍 나온다.

-) 위험분석이 어렵다. 복잡하고 비용이 많이 든다.

# V모델의 특징과 장단점?

테스팅을 빡시게 해서 오류가 발생하면 사람이 죽는 분야에 적합하다.

+) 안전 그자체

-) 테스트가 빡세고 릴리즈가 느리다. 

# RUP모델의 특징?

중간에 고객의 피드백을 받는 evolutionary model + 폭포 모델의 짜임새 있는 단계

# plan & document 모델의 특징?

철저한 계획과 문서화, 수치화된 계획의 진척도

폭포 모델의 변종들.

# 애자일 모델의 특징?

문서보다는 개발에 초점을 두고, 고객과 소통을 더 자주 한다.

모바일, 웹 개발에 잘 맞늗다.

# 요구사항 잘 모르면 전통적인 방식을 따른다.

엿. 유연한 방식(애자일)을 따른다.

# 익숙한 분야라면 전통 방식을 따른다.

맞음.

# 애자일에서 쓰는 방법 2가지

Scrum - 팀 관리 방식

XP - 코드 짜는 방식

# XP(extreme programming)엔 뭐가 있어?

* TDD
* Pari programming
* CI - 미완이지만 빌드는 된다~

# 비행기에 탑재되는 시스템 제어 소프트웨어를 개발할 때 아래 예시 중에 가장 적합하다고 판단되는 개발 모델은?

1. Waterfall✔

2. Agile

3. Prototyping/Evolutionary



# 프로젝트 개발 중간에 수정이 필요하다고 가정할 때 어떤 개발 모델이 가장 적합하다고 생각하는가?

Waterfall

Spiral

Prototyping/Evolutionary ✔

#  Validation과 Verification의 차이점을 확인해보자. 

고객에게 valid해야 하고 개발자는 verify해야한다.

# Validation에 해당하는 설명을 모두 선택하시오.

Did you build the right thing?

Did you meet the specification?✔

Is the specification correct?

Is this what the customer wants?✔

# 다음 예시에서 애자일 모델에 해당하는 항목을 모두 선택하시오.

Comprehensive documentation

Contract negotiation

Customer collaboration✔

Following a plan

Individuals and interactions

Processes and tools

Responding to change✔

Working software✔

# 애자일 방법 스크럼에서 개발할 사항 또는 이슈 사항을 기록한 것을   가리키는 용어는 무엇인가?

backlog



# 애자일 방법 스크럼에서 소프트웨어 개발 주기를 가리키는 용어는   무엇인가?

sprint

# 스크럼 소프트웨어 개발 주기를 마치기 전에 이 개발 주기 동안의   활동을 되돌아보는 활동을 가리키는 용어는 무엇인가?

retrospective

# Sprint backlog는 고객이랑 소통하는 용도다.

엿. 그건 product backlog다. sprint backlog는 work status board 진행 상황을 보여준다.

# 프로그램을 작성하기 전에 이 프로그램을 테스트할 코드를 먼저   작성하고 이 테스트를 통과하도록 코딩하는 애자일 방법을 무엇이라   하는가?

TDD

# swe와 programming의 차이는 무엇인가?

매니징 과정이 포함되야한다.

# sw management엔 무엇이 포함되는가

* 일정
* 비용
* 요구사항 만족
* 팀

# 프로젝트 계획에 포함되어야 하는 요소는?

* 프로젝트 범위
* 팀
* 비용 계획
* 일정
* 프로젝트 매니징

# REP는 무엇의 약자인가?

request for proposal - 제안 요청서



# 프로젝트의 범위는?

* 목표
* 제약 사항
* SOW (statement of work) - 작업 명세서
* 시스템 구성도

# 프로젝트 스케쥴링은?

# 팀 구성은?

# 리스크 관리는 어떻게 해야 할까?



# 개발비용 및 시간을 추정하는 방법을 설명해봐라

* 경험 기반
* 공식 기반

# cocomo 1 공식 뭐게?

Efforts = [sw type 상수] X [KLOC 나 FP  - size임] ^ [1~1.5 사이의 복잡도] X [얼마나 고오급 인력인가 같은 scale or cost driver]

단위는 PM

# 사이즈 기반인 cocomo1 단점

* 우리 뭘 만들지 정하지도 않았는데 규모를 어케 아노..
* 사심 채움
* 아니 언어따라 코드 량 다르잖아요
* 고인물이랑 뉴비가 페이가 같다고?

# 단계별로 공식을 다르게 적용하는 Cocomo2 뭐게?

fp나 비용 / 생산성

# 프로젝트 일정을 세우는 기법을 설명해봐라

* WBS (work breakdown structure)
* CPM (critical path method)
* Gantt chart

# 간트 차트에서 우린 얼마나 게을러도 되는지 알 수 있다. 

맞음.

# CPM의  critical path는 일 끝나는데 최대 얼마나 걸릴지이다.

엿. 일 끝나는데 최소 며칠이 걸리는지이다. 

# 오픈소스 프로젝트는 egoful cooperation을 한다.

엿. egoless 협동을 한다.

# 일반 회사는 chief programmer 협동을 선호한다.

엿. 버스기사는 대학 조별과제이고, 회사는 hierarchical 협력이다.

# PL은 프로젝트 업무를 정의하고, 개발팀과 조직 경영자를연결한다.

엿. PM이다.

# 팀에서 국제화/지역화를 위한 번역 프로세스를 정립하는 포지션은 sw engineer이다.

엿. technical writer이다.

# 개발과 운영을 같이 하는 팀을 뭐라고 부르는가

DevOps

# MLOps는 뭐고

제품의 ml model을관리하는 것.

# 개발자와 모델 검증하는 사람은 MLOps에 없다.

엿. 있음

# 위험 관리 활동을 설명해봐라.

발생할 문제가 뭐가 있을지 나열해보고, 대응 전략을 수립한다.

# 프로젝트 계획에 포함되어야할 항목을 모두 선택하시오.

Statement of work✔

Project team organization✔

Person-month plan✔

Work schedule✔

Risk management✔



# 폭포수 소프트웨어 개발 모델 단계를 가정하고, 개발 노력 (시간과    비용)을 가장 예측하기 어려운 단계는 무엇인가?

Requirement analysis✔

Design

Implementation

Verification/Testing

Maintenance

# COCOMO81과 COCOMOII 비용 모델링/추정 방법의 공통점을 모두 선택하시오.

Algorithmic cost modeling✔

Constructive cost modeling✔

Different models in the progress of software development

Empirical model

Software vendor independent model✔

# CPM 그래프에서 간선(edge)으로 표현하는 바는 무엇인가?

의존성

# CPM에서 프로젝트를 완수하기 위해 필요한 최소 작업 기간을 결정하는 경로를 무엇이라 하는가?*

critical path

# 시장의 빠른 변화에 소프트웨어 개발을 적응하고자 개발팀과 운영팀을  한 팀으로 구성하는 팀 구성 방법을 무엇이라  하는가?

DevOps

# 위험 관리(Risk management) 중 위험 분석(Risk analysis) 활동과 가장 관련이 깊은    사항을 모두 고르시오.*

위험 사항을 지속적으로 모니터링 - risk analysis

위험 유형 (기술, 조직, 비즈니스 환경 등) 파악 - risk identification

위험 해결 방안 마련 - rist resolution

위험으로 인한 피해 효과✔

위험이 발생할 가능성✔

# 시스템이 어떤 방식으로 기능을 제공할지를 정의한게 요구사항이다.

엿. 방식은 안따진다. 어떤 기능을 제공할지가 이슈다.

# 요구사항을 작성할 때 만족해야 할 성질로 적합한 것을 모두 선택하시오.*

Complete✔ - 요구사항 + 익셉션 핸들링 모두 포함

Feasible✔ - 그건 sw의 영역이 아인데요

consistent✔ - 공존할 수 없는 요구사항들

traceable ✔ - 다 필요해서 만든 기능이지?

correct ✔ - 고갱님이 원하면 안되는걸 요구한다.

Reliable

Robust

Unambiguous✔ - 정확한 기준을 말해주세요 고갱님

# 다음 요구사항의 분류 중 나머지와 다른 성격의 항목을 선택하시오.

Ease of use  - quality

Ethical requirements - external constraints

Portability - quality

Regulatory requirements - external constraints

Services (input-output) - ✔기능

# 다음 중 비기능적 요구 사항을 모두 고르시오.*

The BowlingAlley program keeps track of the score during a game.

The WordCount program should be able to process large files. ✔

The Login program for a website should be secure. ✔

The VendingMachine program should take coins as an input from the user.

# 요구 추출을 영어로 작성하시오. (모두 소문자로 작성)

requirements eclicitation

# 요구사항을 얻을 수 있는 정보원/원천/소스를 모두 고르시오.*

Customers✔

Developers

Domain experts✔

Reverse engineering✔

Users✔

# 요구사항 추출 기법에서 나열되지 않은 기법 1가지를 작성하시오.  

Brainstorming / Customer presentation / Interviews / Literature survey / Requirement workshop / Reverse engineering*

protoyping

# sw개발자가 배경 지식을 배우는 단계를 무엇이라 하는가?

domain analysis



# 유스 케이스 모델을 구성하는 가장 중요한 요소 3가지를 나열하시오.    (영어 소문자로 작성하고 알파벳 순서로 콤마로 구분하여 나열)

actor, ,use-case, system scope

# 실행될수도 있고 아닐수도 있는 관계는 extend.

맞음.

# 두개 이상 use cases가 공유하는 usecase 관계?

include relationship

# 상위 관계

use case generalization

# 줄임말 SRS의 영어 본딧말을 작성하시오.

software requirements sepcification

# SRS 문서를 사용하는 대상은?

모든 stakeholders

# 고객이 원하는 소프트웨어 기능을 기술하거나 또는 구현하고자 하는   소프트웨어 구조를 기술한 것을 무엇이라 부르는가?

model

# 소프트웨어의 기능이나 구조를 기술할 때 사용할 수 있는 두 가지 방법론은 무엇인가?

* object oriented methods
* structured methods

# 구조적 프로그램(structured programs)을 작성할 때 주요 제어 흐름을 모두 선택하시오.*

break (반복에서 빠져 나오기)

goto (지정한 라벨로 이동)✔

iteration (반복)✔

sequence (순차)✔

selection (조건부 실행)✔

#  슬라이드 P.10 하단의 데이터 플로우 다이어그램(data-flow diagram) 예시에서 사용한 제어 흐름을 모두 선택하시오.*

break (반복에서 빠져 나오기)

goto (지정한 라벨로 이동)

iteration (반복)

sequence (순차)✔

selection (조건부 실행)✔

# 슬라이드 P.12 데이터 딕셔너리 예시에서 배열이나 리스트로 구현하기 적절한 요소는 무엇인가?

Name

Category

Class

Items✔

No

Stock number

Quantity

Unit price

#  UML 다이어그램을 정적인 성질과 동적인 성질을 기준으로 분류할 수 있다. 이때 객체지향 모델링에서 정적인 성질에 해당하는 예시를 모두 선택하시오.

객체 생성

클래스 상속

객체의 메소드 호출

클래스간 연관

클래스간 의존

인터페이스를 실현하는(구현하는) 클래스

액티비티 흐름

상태와 상태 전이

# 소프트웨어 시스템 내의 클래스간 구성을 표현하는데 적합한 다이어그램은?

class diagram

# 클래스 A가 클래스 B 타입의 멤버 변수를 포함한다면 이 두 클래스는 어떤   관계라 부르는가?

Inclusion

Association✔

Inheritance

Dependence

Realization

#  Slide 25의 클래스 다이어그램 예시에서 Q3의 관계를 이루고 있는 두 개의 클래스 짝을 모두 선택하시오.*

VideoStoreSystem과 Customer✔

Customer와 Adult

Adult와 Child

Rental과 Video✔

Inventory와 Video✔

#  다음 예시 UML 다이어그램 종류에서 나머지 종류들과 성격이 다른 것을 한 가지 선택하시오.*

Class diagram✔

Sequence diagram

Activity diagram

State diagram

Communication diagram