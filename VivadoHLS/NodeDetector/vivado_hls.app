<project xmlns="com.autoesl.autopilot.project" name="NodeDetector" top="nodeDetector">
    <includePaths/>
    <libraryPaths/>
    <Simulation>
        <SimFlow name="csim" csimMode="0" lastCsimMode="2"/>
    </Simulation>
    <files xmlns="">
        <file name="../src/nodedetectorTest.cpp" sc="0" tb="1" cflags=" -Wno-unknown-pragmas" blackbox="false"/>
        <file name="NodeDetector/src/nodedetector.cpp" sc="0" tb="false" cflags="" blackbox="false"/>
        <file name="NodeDetector/src/nodedetector.h" sc="0" tb="false" cflags="" blackbox="false"/>
    </files>
    <solutions xmlns="">
        <solution name="SolutionWithoutPipelining" status="inactive"/>
        <solution name="SolutionWithPipelining" status="active"/>
    </solutions>
</project>

